with open("problem4.txt") as f:
        content = f.read()
content = content.replace("donkey", "######")
with open("problem4.txt", "w") as f:
        f.write(content)