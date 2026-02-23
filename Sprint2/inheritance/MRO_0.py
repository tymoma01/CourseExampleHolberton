class MyInt(int): 
    def __init__(self, value):
        super().__init__(value)

    def __eq__(self, other_value): 
        return not super().__eq__(other_value)




one = MyInt(1)
two = MyInt(2)


one == two # -> True