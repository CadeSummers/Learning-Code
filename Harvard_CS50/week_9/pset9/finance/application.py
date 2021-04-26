import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from tempfile import mkdtemp
from werkzeug.exceptions import default_exceptions, HTTPException, InternalServerError
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True


# Ensure responses aren't cached
@app.after_request
def after_request(response):
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_FILE_DIR"] = mkdtemp()
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")

# Make sure API key is set
if not os.environ.get("API_KEY"):
    raise RuntimeError("API_KEY not set")
    

@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""

    #grab the username using the user's session id in the SQL database
    username = db.execute("SELECT username FROM users WHERE id = :user", user = int(session["user_id"]))[0]["username"]

    #grab the associated cash value of the username in the SQL database
    cash = db.execute("SELECT cash FROM users WHERE username = :username", username=username)[0]["cash"]

    #grab stocks from the database
    stocks = db.execute("SELECT symbol, shares FROM portfolio WHERE user_id=:user_id GROUP BY symbol", user_id=session["user_id"])

    #value of stocks in equity
    value_in_equity = 0

    #breakdown the stock in portfolio to several different values
    for stock in stocks:
        shares = int(stock["shares"])
        symbol = str(stock["symbol"])
        name = lookup(symbol)["name"]
        price = lookup(symbol)["price"]
        stock_value = shares * price
        stock["name"] = name
        stock["price"] = usd(price)
        stock["total"] = usd(stock_value)

        #sum the stock_total value and add it to value in equity
        value_in_equity += stock_value
        

    return render_template("index.html", stocks=stocks, cash=usd(cash), total_value=usd(cash + value_in_equity), value_in_equity=usd(value_in_equity) )


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""

    #if post method invoked
    if request.method == "POST":

        #set symbol and shares equal to form values, set to it's uppercase value
        symbol = request.form.get("symbol")
        shares = int(request.form.get("shares"))
        
        #TODO: FIND A WAY TO HANDLE NUMBERS LIKE 1.5, 2.333, etc. NUMERIC VALUES difficult to handle

        #ensure non-void values
        if symbol == None:
            return apology("TODO")

        if shares == None:
            return apology("TODO")

        #ensure no purchasing of # of shares <1
        if shares < 1:
            return apology("TODO")
            
        #ensure the type of shares is an integer
        if type(shares) != int:
            return apology("TODO")
            
        #ensure the value of shares is a whole number
        if (int(shares)*10) % 10 != 0:
            return apology("TODO")

        #lookup symbol and get share price
        stock = lookup(symbol)

        #if stock symbol returns a non-existant stock, return failure
        if stock == None:
            return apology("TODO")

        #create a value, user_id, equaivalent to the session value at "user_id"
        user_id = session["user_id"]

        #set variable rows equal to the users current session
        rows = db.execute("SELECT cash FROM users WHERE id = :id", id=user_id)
        
        #set variable cash equal to first element of rows at value "cash"
        cash = rows[0]["cash"]

        #indicate the cost being the number of shares desired, plus the number of
        cost = stock["price"]*shares

        #update cash to remove the cost of the stocks bought
        cash -= cost

        #ensure cash balance not less than zero
        if cash < 0:

            #refund the cost to the cash balance
            cash += cost

            #return apology
            return apology("TODO")

        #update the cash value in the the database where the id equals the users' current session id
        db.execute("UPDATE users SET cash=:cash WHERE id=:id", cash=cash, id=user_id)

        #update the history to show changes in stock purchases
        db.execute("INSERT INTO history (user_id, symbol, price, shares) VALUES (:user_id, :symbol, :price, :shares)", user_id=user_id, symbol=symbol, price=stock["price"], shares=shares)
        
        #TODO UPDATE PORTFOLIO WITH NUMBER OF STOCKS OWNED
        
        #insert values into portfolio
        db.execute("INSERT INTO portfolio (symbol, value, shares, user_id) VALUES (:symbol, :price, :shares, :user_id)", symbol=symbol, price=stock["price"], shares=shares, user_id=user_id)
        
        return redirect("/")

    else:
        return render_template("buy.html")


@app.route("/history")
@login_required
def history():
    """Show history of transactions"""

    #get user id
    user_id = session["user_id"]

    #grab users stocks #TODO: add transaction to db.execute
    stocks = db.execute("SELECT symbol, shares, price, time FROM history WHERE user_id=:user_id", user_id=user_id)

    #add the name field to stocks
    for stock in stocks:
        stock_name = lookup(stock["symbol"])
        stock["name"] = stock_name

    #render template
    return render_template("history.html", stocks=stocks)


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE username = ?", request.form.get("username"))

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(rows[0]["hash"], request.form.get("password")):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""

    #if request method is post
    if request.method == "POST":

        #grab symbol from form post in quote.html, and set to upper for ease of use
        symbol = request.form.get("symbol").upper()
        #ensure symbol is non-void
        if not symbol:
            return apology("TODO")
        #initialize variable "stock" to be equal to the return of the lookup function at the value of the symbol. Returns a dictionary object.
        stock = lookup(symbol)
        
        #ensure a valid stock
        if not stock:
            return apology("TODO")
        
        #initialize the value of the stock to be equal to the return of the usd function on the value of the field located at stock["price"]
        stock["price"] = usd(stock["price"])

        #redirect user to a new page, quoted
        return render_template("quoted.html", stock=stock)

    #if request method is GET
    else:
        #send user to quote page
        return render_template("quote.html")


    return apology("TODO")


@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""

    #On user form post
    if request.method == "POST":

        #save username and password to variables
        username = request.form.get("username")
        password = request.form.get("password")

        #ensure non-void entries
        if username == None:
            return apology("TODO")
        if password == None:
            return apology("TODO")
        if request.form.get("confirmation") == None:
            return apology("TODO")
        #if password and confirm password not equivalent
        if password != request.form.get("confirmation"):
            #return apology
            return apology("TODO")
        
        #create list of username   
        db_usernames = db.execute("SELECT username FROM users")
          
        #if username in list db_usernames return failure
        for db_username in db_usernames:
            if db_username["username"] == username:
                return apology("TODO")

        #hash password
        hashpass = generate_password_hash(password)

        #store as registered user username and hashpass
        registered_user = db.execute("INSERT INTO users (username, hash) VALUES (:username, :hash)", username=username, hash=hashpass)

        #ensure valid registration
        if not registered_user:
            return apology("TODO")

        #start a session
        rows = db.execute("SELECT * FROM users WHERE username = :username", username=username)
        session["user_id"] = rows[0]["id"]

        #return to home
        return redirect("/")

    else:
        return render_template("register.html")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""

    #if post method invoked
    if request.method == "POST":

        #set symbol and shares equal to form values
        symbol = request.form.get("symbol")
        shares = int(request.form.get("shares"))
        
        #create a value, user_id, equaivalent to the session value at "user_id"
        user_id = session["user_id"]
        
        #TODO: FIX current_shares LIST DATA TYPE ISSUES
        #grab current shares in portfolio
        current_shares = db.execute("SELECT shares FROM portfolio where user_id=:user_id and symbol=:symbol", user_id=user_id, symbol=symbol)
        
        #create list named total to hold the total number of shares
        total = []
        
        #for each dict in list current_shares
        for current_share in current_shares:
            #append list total to hold the value associated with key "shares" in current_share
            total.append(current_share["shares"])

        #sum the values associated and store in variable total
        total = sum(total)        
        
        #ensure non-void values
        if symbol == None:
            return apology("TODO")

        if shares == None:
            return apology("TODO")
            
        #ensure user does not sell more shares than is owned
        if total - shares < 0:
            return apology("TODO")

        #lookup symbol and get share price
        stock = lookup(symbol)

        #if stock symbol returns a non-existant stock, return failure
        if stock == None:
            return apology("TODO")

        #set variable rows equal to the users current session
        rows = db.execute("SELECT cash FROM users WHERE id = :id", id=user_id)

        #set variable cash equal to first element of rows at value "cash"
        cash = rows[0]["cash"]

        #indicate the cost being the number of shares desired, plus the number of
        value = stock["price"]*shares

        #update cash to add the cost of the stocks bought
        cash += value

        #update the cash value in the the database where the id equals the users' current session id
        db.execute("UPDATE users SET cash=:cash WHERE id=:id", cash=cash, id=user_id)
        
        #reduce total shares value to the value minus the shares
        total-=shares
        
        #if no shares remain, delete the existence of an shares in the portfolio table
        if current_shares == 0:
            db.execute("DELETE FROM portfolio WHERE user_id=:user_id and symbol=:symbol", user_id=user_id, symbol=symbol)
        #otherwise...
        else:
            #update portfolio to value post-sale
            db.execute("UPDATE portfolio SET shares=:shares WHERE user_id=:user_id and symbol=:symbol", shares=total, user_id=user_id, symbol=symbol)
        
        #update history
        db.execute("INSERT INTO history (user_id, symbol, shares, price) VALUES (:user_id, :symbol, :shares, :value)", user_id=user_id, symbol=symbol, shares=shares, value=value)
        
        return redirect("/")

    else:
        return render_template("sell.html")


def errorhandler(e):
    """Handle error"""
    if not isinstance(e, HTTPException):
        e = InternalServerError()
    return apology(e.name, e.code)


# Listen for errors
for code in default_exceptions:
    app.errorhandler(code)(errorhandler)
