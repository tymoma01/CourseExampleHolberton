class Book:
    def __init__(self, title): 
        self.title = title

    def __str__(self): 
        return f"Book: {self.title}"
    
    def __repr__(self): 
        return f"Book({self.title!r})"

b = Book("Python 101")
print(b)
print(repr(b))
