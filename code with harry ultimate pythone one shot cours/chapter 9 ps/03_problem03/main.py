# store the tables of 2 to 20 in different files in a different folder for child

for i in range(2,21):
        f = open(f"table_of_{i}.txt", "w")
        for j in range(1,11):
                f.write(f"{i*j}\n")
                
f.close()
        
