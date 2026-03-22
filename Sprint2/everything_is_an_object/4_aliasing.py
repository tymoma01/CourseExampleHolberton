l = [1, 2, 3]
m = l

m[0] = 'x'
print(l)
print(l is m)


# a = 1
# b = a
# a = 2
# print(b)

# 'a = 2' makes a point to a new object, it doesn't mutate the int 1