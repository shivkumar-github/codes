# comprehension better way to construct a new sequence like list, set , dictionary
# it is a way to create a list from another list
myList = [1,2,9,5,3,5]
# squaredList = []
# for item in myList:
#         squaredList.append(item*item)
        
# also can be done by 
squaredList = [i * i for i in myList]
print(squaredList)