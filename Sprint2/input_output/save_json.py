import json

def save(obj, filename):
    with open(filename, "w", encoding="utf-8") as f:
        json.dump(obj, f)



def load(filename):
    with open(filename, "r", encoding="utf-8") as f:
        return json.load(f)
