from flask import Flask, request, jsonify




app = Flask(__name__)





# The "database"
users = {}





@app.route("/")
def home():
    return "Welcome to the CRUD API! Try /users"


# LIST ALL (GET)
@app.route('/users', methods=['GET'])
def list_users():
    return jsonify(users)


# CREATE (POST)
@app.route('/users', methods=['POST'])
def create_user():
    data = request.get_json()
    if not data:
        return jsonify({"error": "Request body is required"}), 400
    username = data.get("username")
    if not username:
        return jsonify({"error": "Username is required"}), 400

    if username in users:
        return jsonify({"error": "User already exists"}), 400

    users[username] = data
    return jsonify({"message": "User created", "user": users[username]}), 201




# READ (GET)
@app.route('/users/<username>', methods=['GET'])
def read_user(username):
    user = users.get(username)
    if not user:
        return jsonify({"error": "User not found"}), 404
    return jsonify(user)




# UPDATE (PUT)
@app.route('/users/<username>', methods=['PUT'])
def update_user(username):
    if username not in users:
        return jsonify({"error": "User not found"}), 404
    
    data = request.get_json()
    users[username].update(data)
    return jsonify({"message": "User updated", "user": users[username]})






# DELETE (DELETE)
@app.route('/users/<username>', methods=['DELETE'])
def delete_user(username):
    if username not in users:
        return jsonify({"error": "User not found"}), 404
    
    deleted_user = users.pop(username)
    return jsonify({"message": f"User {username} deleted", "user": deleted_user})


if __name__ == "__main__":
    app.run(debug=True)


# CLI:
# List all users or GET all
# curl http://127.0.0.1:5000/users

# Create or POST
# curl -X POST http://127.0.0.1:5000/users -H "Content-Type: application/json" -d '{"username": "alice", "age": 25}'

# Read or GET
# curl http://127.0.0.1:5000/users/alice

# Update or PUT
# curl -X PUT http://127.0.0.1:5000/users/alice -H "Content-Type: application/json" -d '{"age": 26}'

# DELETE (returns the deleted user)
# curl -X DELETE http://127.0.0.1:5000/users/alice

