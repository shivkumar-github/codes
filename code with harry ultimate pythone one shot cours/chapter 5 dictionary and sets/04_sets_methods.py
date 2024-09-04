s  = {1, 5, 5, 23, 56, "harry"}

print(s,type(s))

s.add(566) #the position of new element decide by set itself
print(s, type(s))

# sets are unordered => elements order doesn't matter
# sets are unindexed => can not access element by index
# there is no way to change items in sets but can be replaced
# sets can not contain duplicate values

s.remove(1)
print(s)