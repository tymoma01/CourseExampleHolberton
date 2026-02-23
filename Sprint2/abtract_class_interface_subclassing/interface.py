from typing import Protocol

class JSONSerializable(Protocol):
    def to_json(self) -> str:
        pass

class User:
    def __init__(self, name): 
        self.name = name

    def to_json(self): 
        return f'{{"name": "{self.name}"}}'

def dump(obj: JSONSerializable):
    print(obj.to_json())

dump(User("Alice"))
