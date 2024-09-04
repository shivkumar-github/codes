# touple is immutable
# and touple are written using rounded braces instead of square braces
a = (1,2,45,33, "harry", "apple")
print(a)
print(type(a))

no = a.count(45)
print(no)

i = a.index(45)
print(i)

# print(a.index(4)) throws error
print(2 in a)
print(45 in a)