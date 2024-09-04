# a function game allows user to play the game and returns the score compare the returned score with highscore stored in file and strore new highscore in the file
import random

def game():
        print("You are playing the game : ")
        score = random.randint(1,62)
        print(f"Your score is {score}")
        return score
        

curr_score = game()
f = open("text.txt")

string = f.read()
hscore = int(string)
f.close()
if(hscore < curr_score):
        hscore = curr_score
        f = open("text.txt", "w") 
        f.write(str(hscore))
        f.close()

