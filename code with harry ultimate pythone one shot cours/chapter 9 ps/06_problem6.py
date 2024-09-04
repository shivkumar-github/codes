# check if a file contains the word python

with open("log.txt") as f:
        content = f.read()
        
if("python" in content):
        print("python is present")
else:
        print("python is not present")