# write a programe to print following pattern for n  = 3
#   * 
#  ***
# *****

# n = int(input("Enter the number : "))
n  = 3
max = 2 * n -1
for i in range(1,n+1):
        starno = 2*i-1
        spaceno = int((max - starno)/2)
        # print(spaceno, starno)
        print(" " * spaceno, end="") #by default the print ends with a newline character  
        print("*" * starno)

        
        