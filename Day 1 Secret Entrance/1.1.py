#The actual password is the number of times the dial is left pointing at 0 after any rotation in the sequence.

vfid = open("input.txt")

password = 0
dial = 50
print("The dial starts by pointing at", dial)

for rotation in vfid:
    dir = rotation[0]
    dist = int(rotation[1:-1])

    if dir == 'R':
        dial += dist
    else:
        dial -= dist

    dial %= 100

    if dial == 0:
        print("THE DIAL IS POINTING AT 0")
        password += 1

    print("The dial is rotated", rotation[:-1], "to point at", dial)

print("The actual password is", password)