import pickle

class User:
    def __init__(self, name, flags):
        self.name = name
        self.flags = flags  # e.g., {'is_admin': False}

u = User("Grace", {"is_admin": False})

blob = pickle.dumps(u)         # binary bytes
clone = pickle.loads(blob)     # back to a User instance
print(type(blob), type(clone), clone.name)
