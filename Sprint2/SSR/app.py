from flask import Flask, render_template, request, jsonify, redirect, url_for

app = Flask(__name__)

# Simple in-memory store (demo only)
todos = [
    {"id": 1, "text": "Read course notes", "done": False},
    {"id": 2, "text": "Build SSR+DOM demo", "done": True},
]
next_id = 3

@app.route("/", methods=["GET"])
def home():
    # Render the correct template name
    return render_template("index2.html", todos=todos)

@app.route("/todos", methods=["POST"])
def add_todo():
    global next_id
    text = (request.form.get("text") or "").strip()
    if text:
        todos.append({"id": next_id, "text": text, "done": False})
        next_id += 1
    # SSR fallback (when JS is off)
    return redirect(url_for("home"))

# ---- JSON endpoints used by the DOM (client-side) ----

@app.route("/api/todos", methods=["GET"])
def api_list():
    # Optional filtering support (?q=foo). If you don't use filtering,
    # this still returns the full list.
    q = (request.args.get("q") or "").lower()
    filtered = [t for t in todos if q in t["text"].lower()]
    return jsonify(filtered)

@app.route("/api/todos", methods=["POST"])
def api_add():
    global next_id
    data = request.get_json(force=True, silent=True) or {}
    text = (data.get("text") or "").strip()
    if not text:
        return jsonify({"error": "text required"}), 400
    todo = {"id": next_id, "text": text, "done": False}
    todos.append(todo)
    next_id += 1
    return jsonify(todo), 201

@app.route("/api/todos/<int:tid>", methods=["PATCH"])
def api_toggle(tid):
    for t in todos:
        if t["id"] == tid:
            t["done"] = not t["done"]
            return jsonify(t)
    return jsonify({"error": "not found"}), 404

@app.route("/api/todos/<int:tid>", methods=["DELETE"])
def api_delete(tid):
    idx = next((i for i, t in enumerate(todos) if t["id"] == tid), None)
    if idx is None:
        return jsonify({"error": "not found"}), 404
    todos.pop(idx)
    return "", 204

if __name__ == "__main__":
    app.run(debug=True)
