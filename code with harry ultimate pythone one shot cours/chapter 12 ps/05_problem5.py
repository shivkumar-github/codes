# Store the multiplication tables from problem3 to a txt file
n = int(input("Enter the number : "))
table = [n*i for i in range(1, 11)]
with open("problem5_table.txt", "w") as f:
    f.write(f"{table}")

