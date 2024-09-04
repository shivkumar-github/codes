# replace the following words by # in the txt file
block = ["donkey", "moron", "dog", "fool"]

with open("problem4.txt") as f:
        content = f.read()
        
with open("problem4.txt", "w") as f:
        for i in block:
                content = content.replace(i,"*" * len(i))
        f.write(content)
        