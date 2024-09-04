# create a copy of file using python
with open("problem8.txt") as f:
        with open("problem8_copy.txt", 'w') as x:
                x.write(f.read())
        