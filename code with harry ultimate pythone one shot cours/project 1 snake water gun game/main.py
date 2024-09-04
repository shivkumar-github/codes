'''
1 for snake 
-1 for water
0 for gun
'''
import random

computer = random.choice([-1, 0, 1])
youstr = input("Enter your choice : ")
youDict = {"s" : 1, "w" : -1, "g" : 0}
you = youDict[youstr]
reverseDict = {1 : "snake", -1 : "water", 0 :  "gun"}
print("you choose "  +  reverseDict[you] + " computer choose " + reverseDict[computer])

# as the values are 1 -1 and 0 the subtraction of two values will be related to result
diff = computer -you
if (diff==0) :
        print("draw")
        
elif(diff == -1 or diff == 2):
        print("you loose")
        
else:
        print("you win")

# elif(computer == 1 ):
#         if( you == -1):
#                 print("computer win")
#         elif( you == 0):
#                 print("you win")
        
# elif(computer == -1):
#         if(you == 1):
#                 print("you win")
#         elif(you == 0):
#                 print("computer win")
        
# elif(computer == 0):
#         if(you == -1):
#                 print("you win")
#         elif(you == 1):
#                 print("computer win")