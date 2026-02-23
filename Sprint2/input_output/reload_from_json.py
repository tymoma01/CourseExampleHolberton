
class Student:
    def __init__(self, first, last, age):
        self.first_name = first
        self.last_name = last
        self.age = age

    def reload_from_json(self, mapping):
        for k, v in mapping.items():
            setattr(self, k, v)   # dynamic attribute update
