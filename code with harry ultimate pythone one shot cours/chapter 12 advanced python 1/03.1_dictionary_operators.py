# dictionary merge and update operators
# new operators | and |= allow for merging and updating dictionaries
d1 = {'a' : 1, 'b' : 2}
d2 = {'c' : 3, 'd' : 4}
merged = d1 | d2
print(merged)
print(d1)
d1 |= d2
print(d1)