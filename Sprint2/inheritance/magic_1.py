class Vector:
    def __init__(self, x, y):
        self.x, self.y = x, y
        
    def __add__(self, other): 
        return Vector(self.x + other.x, self.y + other.y)
    
    def __repr__(self): 
        return f"Vector({self.x}, {self.y})"

print(Vector(1, 2) + Vector(3, 4))
