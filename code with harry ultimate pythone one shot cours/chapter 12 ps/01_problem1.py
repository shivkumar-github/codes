# write a program to open three files 11.txt 12.txt and 13.txt if any of these files is not present a message without exiting the program must be printed prompting the same
try:
        with (
                open("11.txt") as f1,
                open("12.txt") as f2,
                open("13.txt") as f3
        ):
                pass
except FileNotFoundError:
        print("All files don't exist!")