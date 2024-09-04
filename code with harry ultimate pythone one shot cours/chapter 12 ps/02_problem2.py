# write a program to print  3rd 5th and 7th element in a list using enumerate function
l = [1,2,3,4,5,6,7,8]
for index,item in enumerate(l):
    if(index == 3 or index == 5 or index == 7):
        print(item)
        