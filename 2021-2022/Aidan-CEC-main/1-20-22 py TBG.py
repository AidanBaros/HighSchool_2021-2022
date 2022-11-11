room = 1
while True:
    if room == 1:
        print("You are in room 1 \nYou can go East")
        x = input("Which way would you like to go\n -- ")
        if x.lower() == "east":
            room = 2
        elif x.lower() == "quit":
            break
        else:
            print("Not an option")
    elif room == 2:
        print("You are in room 2 \nYou can go West or South")
        x = input("Which way would you like to go\n -- ")
        if x.lower() == "west":
            room = 1
        elif x.lower() == "south":
            room = 3
        elif x.lower() == "quit":
            break
        else:
            print("Not an option")
    elif room == 3:
        print("You are in room 3 \nYou can go North or East")
        x = input("Which way would you like to go\n -- ")
        if x.lower() == "north":
            room = 2
        elif x.lower() == "east":
            room = 4
        elif x.lower() == "quit":
            break
        else:
            print("Not an option")
    elif room == 4:
        print("You are in room 4 \nYou can go West")
        x = input("Which way would you like to go\n -- ")
        if x.lower() == "west":
            room = 3
        elif x.lower() == "quit":
            break
        else:
            print("Not an option")
