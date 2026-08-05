from flask import Flask, render_template, jsonify
import threading

from database import cursor
import mqtt_client
from mqtt_client import (
    latest_temp,
    latest_accel,
    latest_pressure,
    latest_battery,
    start_mqtt
)


app = Flask(__name__)


# ----------------------------------------------------
# Dashboard
# ----------------------------------------------------

@app.route("/")
def index():
    return render_template("index.html")


# ----------------------------------------------------
# Live Data
# ----------------------------------------------------

@app.route("/api/live")
def live():
    
    return jsonify({

       "status": mqtt_client.device_status,

        "temperature": latest_temp["temperature"],
        "humidity": latest_temp["humidity"],

        "pressure": latest_pressure["pressure"],

        "voltage": latest_battery["voltage"],
        "current": latest_battery["current"],

        "x": latest_accel["x"],
        "y": latest_accel["y"],
        "z": latest_accel["z"]

    })


# ----------------------------------------------------
# Temperature History
# ----------------------------------------------------

@app.route("/api/temp")
def temp():

    cursor.execute("""
        SELECT *
        FROM temperature_data
        ORDER BY id DESC
        LIMIT 20
    """)

    rows = cursor.fetchall()

    data = []

    for row in rows:

        data.append({

            "id": row[0],
            "temperature": row[1],
            "humidity": row[2],
            "time": row[3]

        })

    return jsonify(data)


# ----------------------------------------------------
# Pressure History
# ----------------------------------------------------

@app.route("/api/pressure")
def pressure():

    cursor.execute("""
        SELECT *
        FROM pressure_data
        ORDER BY id DESC
        LIMIT 20
    """)

    rows = cursor.fetchall()

    data = []

    for row in rows:

        data.append({

            "id": row[0],
            "pressure": row[1],
            "time": row[2]

        })

    return jsonify(data)


# ----------------------------------------------------
# Battery History
# ----------------------------------------------------

@app.route("/api/battery")
def battery():

    cursor.execute("""
        SELECT *
        FROM battery_data
        ORDER BY id DESC
        LIMIT 20
    """)

    rows = cursor.fetchall()

    data = []

    for row in rows:

        data.append({

            "id": row[0],
            "voltage": row[1],
            "current": row[2],
            "time": row[3]

        })

    return jsonify(data)


# ----------------------------------------------------
# Accelerometer History
# ----------------------------------------------------

@app.route("/api/accel")
def accel():

    cursor.execute("""
        SELECT *
        FROM accelerometer_data
        ORDER BY id DESC
        LIMIT 20
    """)

    rows = cursor.fetchall()

    data = []

    for row in rows:

        data.append({

            "id": row[0],
            "x": row[1],
            "y": row[2],
            "z": row[3],
            "time": row[4]

        })

    return jsonify(data)


# ----------------------------------------------------
# Run
# ----------------------------------------------------

if __name__ == "__main__":

    mqtt_thread = threading.Thread(
        target=start_mqtt,
        daemon=True
    )

    mqtt_thread.start()

    app.run(
        host="0.0.0.0",
        port=5000,
        debug=True,
        use_reloader=False
    )
