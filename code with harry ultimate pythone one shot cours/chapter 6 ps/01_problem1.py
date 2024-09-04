# write a programe to find greatest number among four numbers enetered by users

n1 = int(input("Enter first number"))
n2 = int(input("Enter second number"))
n3 = int(input("Enter third number"))
n4 = int(input("Enter fourth number"))

# if(1):
#         a = 4
# print(a) ->> py doesn't uses block scope like cpp

if(n1>=n2):
        ans = n1
else:
        ans = n2
if(n3>ans):
        ans = n3
if(n4 > ans):
        ans = n4

print(ans)
