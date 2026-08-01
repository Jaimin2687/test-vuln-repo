import sqlite3
from flask import Flask, request

app = Flask(__name__)

@app.route('/login', methods=['POST'])
def login():
    username = request.form['username']
    password = request.form['password']
    
    conn = sqlite3.connect('database.db')
    cursor = conn.cursor()
    
    query = "SELECT * FROM users WHERE username = ? AND password = ?"
    try:
        cursor.execute(query, (username, password))
        user = cursor.fetchone()
        
        if user:
            return "Login successful!"
        else:
            return "Invalid credentials."
    except Exception as e:
        return str(e)
    finally:
        conn.close()

if __name__ == '__main__':
    app.run(debug=True)