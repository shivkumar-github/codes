# write a program which checks for the word "python" in the file and returns the line number at which it is present
# with open("problem7.txt") as f:
#         content = f.read()
#         cnt = 0
#         if("python" in content):
#                 string = ""
#                 for i in content:
#                         if(i == "\n" or i == " "):
#                                 if(string == "python"):
#                                         print(cnt + 1)
#                                 if(i=='\n'):
#                                         cnt += 1 #the increament must be done after printing th count othre wise the case in which python word is not at the end of the line will be handled incorrectly
#                                 string =""
#                         else:
#                                 string += i
                
                
#  or 
with open("problem7.txt") as f:
        cnt = 0
        lines = f.readlines()
        for line in lines:
                cnt+=1
                if("python" in line):
                        print(f"yes python is present in line {cnt}")
                        break
        else:
                print("python is not present!")
