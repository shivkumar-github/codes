# # ***
# # * *
# # ***
# # for n = 3
# spaceno = 0
# n = int(input("Enter the number : "))

# # dividing in 3 parts 
# print("*" * n)

# spaceno = 1
# for i in range(1, int(n/2) ):
#         starno = int((n - spaceno)/2)
#         print("*" * starno, end="")
#         print(" " * spaceno, end="")
#         print("*" * starno)
#         spaceno+=2 
        
# print("*" + " " * (n-2) + "*")

# starno = 2
# for i in range(1, int(n/2) ):
#         spaceno = n - starno*2
#         # print(starno, spaceno)
#         print("*" * starno, end="")
#         print(" " * spaceno, end="")
#         print("*" * starno)
#         starno+=1
                
# print("*" * n)


n = 5
print("*"*n)
for i in range (n-2) : 
        print("*" + " "*(n-2) + "*")
print("*"*n)