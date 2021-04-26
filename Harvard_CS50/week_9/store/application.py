from cs50 import SQL
from flask import Flask, redirect, render_template, request, session
from flask_session import Session

# Configure app
app = Flask(__name__)

#Initialize and connect app to database
db = SQL("sqlite:///store.db")

#Configuration of Sessions on web application
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)


@app.route("/")
def index():
    books = db.execute("SELECT * FROM books")
    return render_template("books.html", books=books)
    
@app.route("/cart", methods=["GET","POST"])
def cart():
    
    #ensure existence of cart
    if "cart" not in session:
        session["cart"] = []
        
    #POST method
    if request.method == "POST":
        id = request.form.get("id")
        if id:
            session["cart"].append(id)
        return redirect("/cart")
    
    #GET method
    books=db.execute("SELECT * FROM books WHERE id IN (?)", session["cart"])
    return render_template("cart.html", books=books)
    
    