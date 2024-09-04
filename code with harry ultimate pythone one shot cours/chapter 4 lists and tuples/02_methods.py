# methods change the orignal list unlike of methods on string which create new string
# i.e. list is mutable
friends = ["apple", "akash", 78, 87, True, False]
friends.append("shivkumar")
print(friends)

l1 = [1, 44, 23, 16]
l1.sort()
print(l1)
l1.reverse()
print(l1)

# insert
l1.insert(3,444) # insert at index 3
print(l1)

# pop
print(l1.pop(0))
print(l1[0])

#remove deletes the first occurance of given element
l1.insert(3,23)
print(l1)
l1.remove(23)
print(l1)
