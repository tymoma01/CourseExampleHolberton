import json

profile = {"name": "Ada", "skills": ["math", "logic"], "active": True}

# Serialize (Python -> JSON string)
payload = json.dumps(profile)
print(type(payload), payload)

# Deserialize (JSON string -> Python)
back = json.loads(payload)
print(type(back), back)

# Tip: save/load files
with open("profile.json", "w", encoding="utf-8") as f:
    json.dump(profile, f)
    
with open("profile.json", "r", encoding="utf-8") as f:
    loaded = json.load(f)
