class P:

    @property
    def x(self): 
        return 1

p = P()
print(p.__dict__)
p.__dict__['x'] = 999
print(p.__dict__)
print(p.x)
