numbers = [1, 2, 3]

# print(numbers[10])



try:
    print(numbers[10])
except IndexError:
    print("Out of range!")



def divide(a, b):
    try:
        return a / b
    except ZeroDivisionError:
        print("You cannot divide by 0")
    # if b == 0:
    #     raise ValueError("Cannot divide by zero")
    # return a / b
