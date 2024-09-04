# there are two types of file 
# textable and binary

f = open("file.txt")
data = f.read()
print(data)
f.close()

# modes for opening 
# 'r' - for reading
# 'w' - for writing
# 'a' - for appending
# '+' - for updating
# 'rb'- for read in binary
# 'rt' - for reading in text