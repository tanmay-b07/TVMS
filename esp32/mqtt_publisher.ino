#include <WiFi.h>
#include <PubSubClient.h>
#include <ArduinoJson.h>

#define RXD2 16
#define TXD2 17

// ---------------- WiFi ----------------

const char* ssid = "wifi";
const char* password = "pass";

// ---------------- MQTT ----------------

const char* mqtt_server = "ip_addr";
const int mqtt_port = 1883;

#define TOPIC_TEMP      "talktrail/vehicle/temp"
#define TOPIC_ACCEL     "talktrail/vehicle/accel"
#define TOPIC_PRESSURE  "talktrail/vehicle/pressure"
#define TOPIC_BATTERY   "talktrail/vehicle/battery"
#define TOPIC_STATUS    "talktrail/vehicle/status"

WiFiClient espClient;
PubSubClient client(espClient);

String uartData = "";

unsigned long heartbeatTimer = 0;

// ------------------------------------------------------------

void connectWiFi()
{
  if (WiFi.status() == WL_CONNECTED)
    return;

  Serial.println("\nConnecting WiFi...");

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }

  Serial.println();
  Serial.println("WiFi Connected");
  Serial.print("IP : ");
  Serial.println(WiFi.localIP());
}

// ------------------------------------------------------------

void reconnect()
{
  while (!client.connected())
  {
    Serial.print("Connecting MQTT... ");

    if (client.connect(
          "TVMS_ESP32",
          NULL,
          NULL,
          TOPIC_STATUS,
          1,
          true,
          "offline"))
    {
      Serial.println("Connected");

      client.publish(TOPIC_STATUS,
                     "online",
                     true);
    }
    else
    {
      Serial.print("Failed : ");
      Serial.println(client.state());
      delay(2000);
    }
  }
}

// ------------------------------------------------------------

void heartbeat()
{
  if (millis() - heartbeatTimer >= 500)
  {
    heartbeatTimer = millis();

    client.publish(TOPIC_STATUS,
                   "online",
                   true);

    Serial.println("Heartbeat Sent");
  }
}

// ------------------------------------------------------------

void setup()
{
  Serial.begin(115200);

  Serial2.begin(115200,
                SERIAL_8N1,
                RXD2,
                TXD2);

  connectWiFi();

  client.setServer(mqtt_server,
                   mqtt_port);
  client.setKeepAlive(5);       // Detect disconnect in ~5-10 sec
  client.setSocketTimeout(3);   
}

// ------------------------------------------------------------

void loop()
{
  connectWiFi();

  if (!client.connected())
    reconnect();

  client.loop();

  heartbeat();

  while (Serial2.available())
  {
    char c = Serial2.read();

    if (c == '\n')
    {
      uartData.trim();

      if (uartData.length())
      {
        Serial.print("UART : ");
        Serial.println(uartData);

        StaticJsonDocument<256> doc;

        DeserializationError error =
            deserializeJson(doc,
                            uartData);

        if (!error)
        {
          const char *type = doc["type"];

          if (type == NULL)
          {
            Serial.println("Invalid JSON Type");
            uartData = "";
            continue;
          }

          // -------- Sensor Handling Continues --------
          // ---------------- Temperature ----------------

          if (strcmp(type, "temp") == 0)
          {
            StaticJsonDocument<128> out;

            out["temperature"] = doc["temperature"];
            out["humidity"] = doc["humidity"];

            char payload[128];
            serializeJson(out, payload);

            if (client.publish(TOPIC_TEMP, payload))
            {
              Serial.print("Published Temp : ");
              Serial.println(payload);
            }
          }

          // ---------------- Accelerometer ----------------

          else if (strcmp(type, "accel") == 0)
          {
            StaticJsonDocument<128> out;

            out["x"] = doc["x"];
            out["y"] = doc["y"];
            out["z"] = doc["z"];

            char payload[128];
            serializeJson(out, payload);

            if (client.publish(TOPIC_ACCEL, payload))
            {
              Serial.print("Published Accel : ");
              Serial.println(payload);
            }
          }

          // ---------------- Pressure ----------------

          else if (strcmp(type, "pressure") == 0)
          {
            StaticJsonDocument<128> out;

            out["pressure"] = doc["value"];

            char payload[128];
            serializeJson(out, payload);

            if (client.publish(TOPIC_PRESSURE, payload))
            {
              Serial.print("Published Pressure : ");
              Serial.println(payload);
            }
          }

          // ---------------- Battery ----------------

          else if (strcmp(type, "battery") == 0)
          {
            StaticJsonDocument<128> out;

            out["voltage"] = doc["voltage"];
            out["current"] = doc["current"];

            char payload[128];
            serializeJson(out, payload);

            if (client.publish(TOPIC_BATTERY, payload))
            {
              Serial.print("Published Battery : ");
              Serial.println(payload);
            }
          }

          // ---------------- Unknown Packet ----------------

          else
          {
            Serial.print("Unknown Packet Type : ");
            Serial.println(type);
          }
        }
        else
        {
          Serial.print("JSON Error : ");
          Serial.println(error.c_str());
        }
      }

      uartData = "";
    }
    else
    {
      uartData += c;
    }
  }
}
