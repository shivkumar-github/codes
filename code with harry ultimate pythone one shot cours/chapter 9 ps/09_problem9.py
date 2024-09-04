# check if two files are identical or not
with open("problem91.txt") as f:
        with open("problem92.txt") as f1:
                print(f.read()==f1.read())