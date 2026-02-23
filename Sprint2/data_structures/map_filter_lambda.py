numbers = [1, 2, 3, 4]

def function1(a):
    return a*a

squared = list(map(lambda number: number*number, numbers))
print(squared)







even = list(filter(lambda x: x % 2 == 0, numbers))
print(even)
