from cs50 import SQL
from flask import Flask, redirect, render_template, request
from flask_mail import Mail, Message

#defines this program as a Flask application
app = Flask(__name__)

SPORTS = ["Dodgeball", "Flag Football", "Soccer", "Volleyball", "Ultimate Frisbee"]

REGISTRANTS = {}

#db = SQL("sqlite:///froshims.db")

#define default route
@app.route("/")

#define define pull for index.html
def index():
    return render_template("index.html", sports=SPORTS)

#define register route, with necessary method post
@app.route("/register", methods=["POST"])

#define register function
def register():
    
    name = request.form.get("name")
    sport = request.form.get("sport")
    
    if not name:
        return render_template("error.html", message="Missing name")
    if not sport:
        return render_template("error.html", message="Missing sport")
    if sport not in SPORTS:
        return render_template("error.html", message="Invalid sport")

    REGISTRANTS[name] = sport
    
    print(REGISTRANTS)
    
    return redirect("/registrants")
    
#definte registrants route
@app.route("/registrants")

#define registrants function
def registrants():
    return render_template("registrants.html", registrants=REGISTRANTS)
    