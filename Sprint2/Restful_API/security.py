# demo_security.py
from flask import Flask, jsonify, request
from werkzeug.security import generate_password_hash, check_password_hash
from flask_httpauth import HTTPBasicAuth
from flask_jwt_extended import (
    JWTManager, create_access_token, jwt_required, get_jwt
)

import os
from dotenv import load_dotenv
load_dotenv()


app = Flask(__name__)

# NEVER hardcode KEYS in apps: use .env
app.config["JWT_SECRET_KEY"] = os.getenv("JWT_SECRET_KEY")
jwt = JWTManager(app)

# In-memory users (hashed passwords and roles included)
USERS = {
    "user1":  {"username": "user1",  "password": generate_password_hash("password0"), "role": "user"},
    "admin1": {"username": "admin1", "password": generate_password_hash("password1"), "role": "admin"},
}

# BASIC AUTH section
basic_auth = HTTPBasicAuth()


@basic_auth.verify_password
def verify_basic(username, password):
    u = USERS.get(username)
    if not u:
        return None
    if not check_password_hash(u["password"], password):
        return None
    return username

@app.get("/")
def root():
    return "Welcome to the Security Demo!"

@app.get("/basic-protected")
@basic_auth.login_required
def basic_protected():
    # If credentials are wrong, Flask-HTTPAuth will return error 401 automatically
    return "Basic Auth: Access Granted"


# ---- JWT AUTH section ----
@app.post("/login")
def login():
    """
    Accepts JSON: { "username": "...", "password": "..." }
    If valid, returns: { "access_token": "<JWT>" }
    """
    if not request.is_json:
        return jsonify({"error": "Expected JSON"}), 400
    
    data = request.get_json(silent=True) or {}
    username = data.get("username", '')
    password = data.get("password", '')

    u = USERS.get(username)
    if not u or not check_password_hash(u["password"], password):
        # Auth failure → 401
        return jsonify({"error": "Invalid credentials"}), 401

    # Put minimal info in token; include role for authorization checks
    claims = {"role": u["role"]}
    token = create_access_token(identity=username, additional_claims=claims)
    return jsonify({"access_token": token})

@app.get("/jwt-protected")
@jwt_required()
def jwt_protected():
    return "JWT Auth: Access Granted"

@app.get("/admin-only")
@jwt_required()
def admin_only():
    claims = get_jwt()  # contains 'role' added at login
    if claims.get("role") != "admin":
        # Authenticated but not allowed → 403
        return jsonify({"error": "Admin access required"}), 403
    return "Admin Access: Granted"


# ---- Uniform JWT error handling (all 401 for auth/token problems) ----
@jwt.unauthorized_loader
def _unauthorized(msg):
    return jsonify({"error": "Missing or invalid token"}), 401

@jwt.invalid_token_loader
def _invalid(msg):
    return jsonify({"error": "Invalid token"}), 401

@jwt.expired_token_loader
def _expired(header, payload):
    return jsonify({"error": "Token has expired"}), 401


if __name__ == "__main__":
    app.run(debug=False)



# CLI
# curl -i http://127.0.0.1:5000/basic-protected

# curl -i --user user1:password http://127.0.0.1:5000/basic-protected

# TOKEN=$(curl -s -X POST -H "Content-Type: application/json" \
#   -d '{"username":"user1","password":"password0"}' \
#   http://127.0.0.1:5000/login | python -c "import sys, json; print(json.load(sys.stdin)['access_token'])")

# echo $TOKEN

# Missing token → 401
# curl -i http://127.0.0.1:5000/jwt-protected

# With token → 200
# curl -i -H "Authorization: Bearer $TOKEN" http://127.0.0.1:5000/jwt-protected


# user1 is NOT admin → 403
# curl -i -H "Authorization: Bearer $TOKEN" http://127.0.0.1:5000/admin-only

# login as admin1, then try again
# ADMIN=$(curl -s -X POST -H "Content-Type: application/json" \
#   -d '{"username":"admin1","password":"password1"}' \
#   http://127.0.0.1:5000/login | python -c "import sys, json; print(json.load(sys.stdin)['access_token'])")

# curl -i -H "Authorization: Bearer $ADMIN" http://127.0.0.1:5000/admin-only