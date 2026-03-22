#  
def double(n):
    n = n * 2

x = 5
double(x)
print(x)










#  
def add_item(lst):
    lst.append(99)

my_list = [1, 2, 3]
add_item(my_list)
print(my_list)











# 
def replace(lst):
    lst = [0, 0, 0]   # local name 'lst' now points elsewhere — caller unaffected

my_list = [1, 2, 3]
replace(my_list)
print(my_list)