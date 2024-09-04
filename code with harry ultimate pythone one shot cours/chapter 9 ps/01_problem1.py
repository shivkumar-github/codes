# write a program to read text from poem.txt and check whether it contains twinkle word
def game():
        f = open("text.txt")
        text = f.read()
        word = "twinkle"
        if(word in text):
                print("yes")
        else:
                print("no")
        f.close()
        
game



