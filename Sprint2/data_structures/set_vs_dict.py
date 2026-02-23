# numbers = [1, 2, 2, 3, 3, 3]
# unique = set(numbers)

# print(unique)

# A = {1, 2, 3, 4}
# B = {3, 4, 5, 6}

# print(A & B)    # intersection → {3, 4}
# print(A | B)    # union → {1,2,3,4,5,6}
# print(A - B)    # difference → {1,2}

# ----------------------------------------------

student = {
    "name": "Alice",
    "age": 21,
    "grade": 85
}
# the json format

print(student["name"])

if "name" in student.keys():
    print("Access granted")

