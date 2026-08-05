import mysql.connector

db = mysql.connector.connect(
    host="localhost",
    user="user_name",
    password="pass",
    database="tvms"
)

cursor = db.cursor()
