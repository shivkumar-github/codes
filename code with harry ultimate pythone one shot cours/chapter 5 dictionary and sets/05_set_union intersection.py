s1 = {1, 34, 67, 70, 50 , 99}
s2 = {5, 77, 90, 70, 50, 99}
s2_sub = {5, 90, 50}

print(s1.union(s2))
print(s1.intersection(s2))
print(s2 - s1)
print(s2_sub.issubset(s2))
print(s2_sub.issuperset(s2)) #super set is set that contains subset