class Basket:
    def __init__(self): 
        self.items = []
    
    def __len__(self): 
        return len(self.items)
    
    def __getitem__(self, i): 
        return self.items[i]
    
    def add(self, item): 
        self.items.append(item)

b = Basket()
b.add("apple")
b.add("pear")

print(len(b))
print(b[0])
