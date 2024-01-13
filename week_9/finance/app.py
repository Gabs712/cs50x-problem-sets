import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd

from datetime import datetime
# Configure application
app = Flask(__name__)

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""

    # get static values from the purchases table (symbol, shares)
    history_values = db.execute('SELECT symbol, shares AS shares FROM shares WHERE user_id = ?', session['user_id'])

    # set grand_total base values
    grand_total = []

    # append dinamic values (price, total)
    for row in history_values:

        # get updated price
        current_price = lookup(row['symbol'])['price']

        # converting shares to float
        shares = float(row['shares'])

        # getting total multiplying the shares with the current stock price
        total = shares * current_price
        grand_total.append(total)

        # appending in dollar format
        row['price'] = usd(current_price)
        row['total'] = usd(total)
        row['name'] =  lookup(row['symbol'])['name']

    # set current cash
    cash = db.execute('SELECT cash FROM users WHERE id = ?', session['user_id'])[0]['cash']
    grand_total = cash + sum(grand_total)

    return render_template('index.html', values=history_values, cash=usd(cash), grand_total=usd(grand_total))


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""
    if request.method == 'GET':
        return render_template('buy.html')
    else:
        symbol = request.form.get('symbol').lower().strip()
        shares = request.form.get('shares')

        stock = lookup(symbol)

        # validate input
        if not symbol:
            return apology('must provide a symbol')
        elif not shares:
            return apology('must provide a share')
        elif not shares.isdigit():
            return apology('must provide a number')
        elif not stock:
            return apology('invalid symbol')
        elif float(shares) < 1:
            return apology('provide a positive number')
        elif '.' in shares:
            return apology('float not allowed')

        user_cash = db.execute('SELECT * FROM users WHERE id = ?', session["user_id"])[0]['cash']
        total_price = stock['price'] * float(shares)

        # check if it is affordable
        if total_price > user_cash:
            return apology('can\'t afford it')

        # remove spend cash
        db.execute('UPDATE users SET cash = ? WHERE id = ?', (user_cash - total_price), session["user_id"])

        time = datetime.now().strftime("%Y-%m-%d %H:%M:%S")

        # inject data into purchases
        db.execute('INSERT INTO purchases VALUES(?, ?, ?, ?, ?)', session["user_id"], symbol.lower(), stock['price'], shares, time)

        #inject data into shares
        register = db.execute('SELECT * FROM shares WHERE user_id = ?', session['user_id'])

        # upgrade value of shares if there is a share register
        for row in register:
            if symbol.lower() == row['symbol']:
                row['shares']+= float(shares)
                db.execute('UPDATE shares SET shares = ? WHERE user_id = ? AND symbol = ?', row['shares'], session['user_id'], symbol)
                return redirect('/')

        # if there's no share in register create one
        db.execute('INSERT INTO shares VALUES(?, ?, ?)', session['user_id'], symbol.lower(), shares)
        return redirect('/')


@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    history = db.execute('SELECT * FROM purchases')

    return render_template('history.html', history=history)


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
    if request.method == 'GET':
        return render_template('quote.html')
    else:
        stock = lookup(request.form.get('symbol'))

        # no symbol or invalid
        if not request.form.get('symbol'):
            return apology('must provide a symbol')
        elif not stock:
            return apology('invalid symbol')

        # render passing stock
        return render_template('quoted.html', stock=stock, usd_price=usd(stock['price']))


@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""
    session.clear()

    if request.method == 'GET':
        return render_template('register.html')
    else:
        username = request.form.get('username')
        password = request.form.get('password')
        confirmation = request.form.get('confirmation')
        rows = db.execute('SELECT * FROM users WHERE username = ?', username)

        # check if there is a input
        if not username:
            return apology('must provide username')
        elif not password:
            return apology('must provide password')
        elif not confirmation:
            return apology('must provide confirmation')

        # check if passwords don't match
        elif password != confirmation:
            return apology('the passwords do not match')
        elif len(password) < 6:
            return apology('the password must have at least 6 characters')

        # check if user is in database
        elif rows:
            return apology('username already exists')

        # insert user into database
        db.execute('INSERT INTO users(username, hash) VALUES(?, ?)', username, generate_password_hash(password))

        # log-in user
        session['user_id'] = db.execute('SELECT * FROM users WHERE username = ?', username)[0]['id']
        return redirect('/')

@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""

    stock = db.execute('SELECT * FROM shares WHERE user_id = ?', session['user_id'])

    if request.method == 'GET':
        return render_template('sell.html', stock=stock)

    else:
        owned_shares = [row['symbol'] for row in stock]
        symbol = request.form.get('symbol')
        share = request.form.get('shares')

        # validation
        if not symbol:
            return apology('invalid symbol')
        elif not share:
            return apology('insert a share')
        elif float(share) < 1:
            return apology('insert a postive number')
        elif symbol not in owned_shares:
            return apology('invalid symbol')

        # sold more shares than owned
        modified_share = float(db.execute('SELECT * FROM shares WHERE user_id = ? AND symbol = ?', session['user_id'], symbol.lower())[0]['shares'])

        if float(share) > modified_share:
            return apology('you don\'t have enough shares to sell')

        # modify cash
        cash = float(db.execute('SELECT cash FROM users WHERE id = ?', session['user_id'])[0]['cash'])
        new_cash = (float(lookup(symbol)['price']) * float(share)) + cash
        db.execute('UPDATE users SET cash = ? WHERE id = ?', new_cash, session['user_id'])

        # decrease shares
        modified_share -= float(share)
        db.execute('UPDATE shares SET shares = ? WHERE user_id = ? AND symbol = ?', modified_share, session['user_id'], symbol.lower())

        # register operation
        time = datetime.now().strftime("%Y-%m-%d %H:%M:%S")
        db.execute('INSERT INTO purchases VALUES(?, ?, ?, ?, ?)', session["user_id"], symbol.lower(), lookup(symbol.lower())['price'], modified_share, time)

        # delete nulified shares
        if modified_share <= 0:
            db.execute('DELETE FROM shares WHERE user_id = ? AND symbol = ?', session['user_id'], symbol.lower())

        return redirect('/')
