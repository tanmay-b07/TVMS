import json
import time

import paho.mqtt.client as mqtt
import mysql.connector

# ---------------- Database ----------------

db = mysql.connector.connect(
    host="localhost",
    user="username",
    password="pass",
    database="tvms"
)

cursor = db.cursor()

# ---------------- Latest Values ----------------

latest_temp = {
    "temperature": 0,
    "humidity": 0
}

latest_accel = {
    "x": 0,
    "y": 0,
    "z": 0
}

latest_pressure = {
    "pressure": 0
}

latest_battery = {
    "voltage": 0,
    "current": 0
}

device_status = "offline"

# ---------------- MQTT ----------------

BROKER = "localhost"
PORT = 1883


def on_connect(client, userdata, flags, rc):

    if rc == 0:

        print("MQTT Connected")

        client.subscribe("talktrail/vehicle/#")

    else:

        print("Connection Failed :", rc)


def on_disconnect(client, userdata, rc):

    global device_status

    device_status = "offline"
    print("Disconnected RC =", rc)

    print("MQTT Disconnected")


def on_message(client, userdata, msg):

    global device_status

    topic = msg.topic

    try:

        if topic == "talktrail/vehicle/status":

            device_status = msg.payload.decode()

            print("Status :", device_status)

            return

        payload = json.loads(msg.payload.decode())

        # ---------------- Temperature ----------------

        if topic == "talktrail/vehicle/temp":

            latest_temp["temperature"] = payload["temperature"]
            latest_temp["humidity"] = payload["humidity"]

            cursor.execute(
                """
                INSERT INTO temperature_data
                (temperature,humidity)
                VALUES(%s,%s)
                """,
                (
                    payload["temperature"],
                    payload["humidity"]
                )
            )

            db.commit()

            print("Temperature Stored")

        # ---------------- Accelerometer ----------------

        elif topic == "talktrail/vehicle/accel":

            latest_accel["x"] = payload["x"]
            latest_accel["y"] = payload["y"]
            latest_accel["z"] = payload["z"]

            cursor.execute(
                """
                INSERT INTO accelerometer_data
                (x,y,z)
                VALUES(%s,%s,%s)
                """,
                (
                    payload["x"],
                    payload["y"],
                    payload["z"]
                )
            )

            db.commit()

            print("Accelerometer Stored")

        # ---------------- Pressure ----------------

        elif topic == "talktrail/vehicle/pressure":

            latest_pressure["pressure"] = payload["pressure"]

            cursor.execute(
                """
                INSERT INTO pressure_data
                (pressure)
                VALUES(%s)
                """,
                (
                    payload["pressure"],
                )
            )

            db.commit()

            print("Pressure Stored")

        # ---------------- Battery ----------------

        elif topic == "talktrail/vehicle/battery":

            latest_battery["voltage"] = payload["voltage"]
            latest_battery["current"] = payload["current"]

            cursor.execute(
                """
                INSERT INTO battery_data
                (voltage,current)
                VALUES(%s,%s)
                """,
                (
                    payload["voltage"],
                    payload["current"]
                )
            )

            db.commit()

            print("Battery Stored")

    except Exception as e:

        print("Error :", e)


client = mqtt.Client()

client.on_connect = on_connect
client.on_disconnect = on_disconnect
client.on_message = on_message


# ---------------- MQTT Starter ----------------

def start_mqtt():

    while True:

        try:

            client.connect(BROKER, PORT, 60)

            client.loop_forever()

        except KeyboardInterrupt:

            break

        except Exception as e:

            print("Reconnecting in 5 seconds...", e)

            time.sleep(5)


# ---------------- Standalone Run ----------------

if __name__ == "__main__":

    start_mqtt()
