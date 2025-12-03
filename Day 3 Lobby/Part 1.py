vfid = open("input.txt")

totaljoltage = 0

#Go through each bank of batteries of our input
for bank in vfid:
    joltage = 0

    #Find the largest possible joltage of the first battery
    for digit in range(9, 0, -1):
        index = bank[: -2].find(str(digit))
                                
        #When found, update the joltage and the searchable bank
        if ((index != -1) and (joltage == 0)):            
            joltage = digit
            subbank = bank[index + 1 : -1]

    #Repeat for the second battery
    for digit in range(9, 0, -1):
        index = subbank.find(str(digit))

        #When found, update the joltage and add it to the total
        if ((index != -1) and (joltage < 10)):            
            joltage = 10 * joltage + digit

    totaljoltage += joltage

vfid.close()
    
print("The total output joltage is", totaljoltage)
