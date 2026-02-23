import json


data = {
            "name": "Ada", 
            "skills": ["math", "logic"], 
            "active": True
        }

s = json.dumps(data)          # Python dictionnary -> JSON string
print(type(s))
print(s)
back = json.loads(s)          # JSON string -> Python dictionnary
print(type(back))
