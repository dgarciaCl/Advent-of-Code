vfid = open("test.txt")

RedTiles = []

for line in vfid: # Read the contents of our input
    comma = line.find(",")

    # Append the location of each red tile to a list
    RedTiles.append([int(line[: comma]), int(line[comma + 1 : -1])])

vfid.close()