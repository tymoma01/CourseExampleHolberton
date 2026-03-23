# a = [1, 2, 3]
# # shallow clone
# b = a[:]

# b[0] = 99
# print(a)
# print(a is b)


import copy

a = [[1, 2], [3, 4]]
b = a[:]
c = copy.deepcopy(a)

print(a)
a[0].append(99)
print(a)
print(b)
print(c)