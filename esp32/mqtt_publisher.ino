#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <PubSubClient.h>

#define RXD2 16
const char* ssid = "your_wifi_name";
const char* password = "your_wifi_password";

const char* mqtt_server = "mqtt_server_url";
const char* mqtt_user = "mqtt_username";
const char* mqtt_pass = "mqtt_password";

WiFiClientSecure espClient;
PubSubClient client(espClient);

String data = "";
unsigned long lastHeartbeat = 0;
const unsigned long HEARTBEAT_INTERVAL = 5000;

void connectMQTT()
{
  while (!client.connected())
  {
    Serial.print("Connecting MQTT... ");

    if (client.connect("ESP32_Client", mqtt_user, mqtt_pass))
    {
      Serial.println("Connected");
    }
    else
    {
      Serial.println("Failed");
      delay(2000);
    }
  }
}

void setup()
{
  Serial.begin(115200);
  Serial2.begin(115200, SERIAL_8N1, RXD2, -1);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nWiFi Connected");

  espClient.setInsecure();

  client.setServer(mqtt_server, 8883);

  connectMQTT();
}

void loop()
{
  if (!client.connected())
  {
    connectMQTT();
  }

  client.loop();
  
 if(millis() - lastHeartbeat >= HEARTBEAT_INTERVAL)
{
  client.publish(
    "your_mqtt_topic",
    "online"
  );

  Serial.println("Heartbeat Sent");

  lastHeartbeat = millis();
}
  while (Serial2.available())
  {
    char c = Serial2.read();

    if (c == '\n')
    {
      data.trim();

      if (data.length() > 0)
      {
        Serial.print("Publishing: ");
        Serial.println(data);

        client.publish(
          "your_mqtt_topic",
          data.c_str()
        );
      }

      data = "";
    }
    else
    {
      data += c;
    }
  }
}
