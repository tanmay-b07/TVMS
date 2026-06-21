#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <PubSubClient.h>

#define RXD2 16
const char* ssid = "your_wifi_ssid";
const char* password = "your_wifi_pass";

const char* mqtt_server = "__server__address";
const char* mqtt_user = "__username__";
const char* mqtt_pass = "__pass__";

WiFiClientSecure espClient;
PubSubClient client(espClient);

String data = "";
unsigned long lastHeartbeat = 0;
const unsigned long HEARTBEAT_INTERVAL = 5000;

void connectMQTT()
{
  Serial.println("Trying MQTT Connection...");

  while (!client.connected())
  {
    if (client.connect("ESP32_Client", mqtt_user, mqtt_pass))
    {
      Serial.println("MQTT Connected");
    }
    else
    {
      Serial.print("Failed. State=");
      Serial.println(client.state());
      delay(2000);
    }
  }
}
void setup()
{
  Serial.begin(115200);
  Serial2.begin(115200, SERIAL_8N1, RXD2, -1);
  Serial.println("\nTVMS:Trailbox Vechicle Monitering System");

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
  if (WiFi.status() != WL_CONNECTED)
  {
    Serial.println("WiFi Lost");

    WiFi.reconnect();

    while (WiFi.status() != WL_CONNECTED)
    {
      delay(500);
      Serial.print(".");
    }

    Serial.println("\nWiFi Reconnected");
  }

  if (!client.connected())
  {
    Serial.print("MQTT Disconnected. State = ");
    Serial.println(client.state());

    connectMQTT();
  }

  client.loop();

  if (millis() - lastHeartbeat >= HEARTBEAT_INTERVAL)
  {
    Serial.print("RSSI: ");
    Serial.println(WiFi.RSSI());

    if (client.publish("talktrail/vehicle/status", "online"))
    {
      Serial.println("Heartbeat Sent");
    }
    else
    {
      Serial.println("Heartbeat Failed");
    }

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
        Serial.print("Raw: ");
        Serial.println(data);

        float ldr = 0;
        float temp = 0;
        float hum = 0;

        sscanf(data.c_str(),
               "LDR:%f,TEMP:%f,HUM:%f",
               &ldr,
               &temp,
               &hum);

        char buf[20];

        dtostrf(ldr, 0, 0, buf);
        client.publish("talktrail/vehicle/ldr", buf);

        dtostrf(temp, 0, 1, buf);
        client.publish("talktrail/vehicle/temp", buf);

        dtostrf(hum, 0, 1, buf);
        client.publish("talktrail/vehicle/humidity", buf);

        Serial.printf(
          "LDR=%.0f TEMP=%.1f HUM=%.1f\n",
          ldr,
          temp,
          hum
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
