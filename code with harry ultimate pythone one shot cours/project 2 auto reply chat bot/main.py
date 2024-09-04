# guess the random number
# computer picks a number and the user tries to guess it ...when use guess it less it shows "choose greater number"  and when user guesses a lesser number it shows "guess a larger number" this continues till user guesses correct number
import random as random
def game():
        n = random.randint(1,300)
        print(n)
        guessNo = 0
        userGuess = n-1
        while(userGuess != n):
                userGuess = int(input("Enter your guess : "))
                guessNo += 1
                if(userGuess < n):
                        print("Please guess a greater number : ")
                elif(userGuess>n):
                        print("Please guess a smaller number : ")
        print(f"You have guessed the number correclty in {guessNo} guesses!")
        
game()