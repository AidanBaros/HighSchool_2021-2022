'''
#File I/O Example
  
# Opening a file
saveFile = open('save.txt', 'w') #if "save.txt" doesn't exist, it's created here!
inventory = ("key", "bread", "dirty sock")
PlayerName = ("Clambraham", "Moregil")
money = (str(5))

tupList = [PlayerName, money, inventory]

#write stuff to the file
#saveFile.write(PlayerName) #for writing one thing
#saveFile.write(str(money)) #I think the write function only wants strings
#saveFile.writelines(inventory) #for lots of stuff
for t in tupList:
    line = ' '.join(str(x) for x in t)
    saveFile.write(line + '\n')
#saveFile.write(str(tup1)).
saveFile.close()
  
#testing if it worked:
saveFile = open('save.txt', 'r')
print("here's what we just saved:")
print(saveFile.read())
saveFile.close()

#read each line
saveFile = open('save.txt', 'r')
NewPlayerName = saveFile.readline()
NewMoney = saveFile.readline()
NewInventory = saveFile.read() #read the rest of the file (i think this saves to a tuple?)
saveFile.close()

#test again:
print("Printing out new variables just loaded:")
print(NewPlayerName)
print(NewMoney)
print(NewInventory)
'''

room = 1
answer = "a"
sf = open('save.txt', 'r')
NewRoom = sf.readline()
sf.close()

x = input("Do you want to continue. y/n \n")

if x == "y":
    room = int(NewRoom)
else:
    pass


print ("Welcome to Dreadsky! explore the map. Press esc to exit.")

while answer != "q":
    if room == 1:
        print ("you are in the Barracks, you can go E")
        answer = input()
        if answer == "e":
            room = 2
    elif room == 2:
        print ("you are in the Cafeteria , you can go W or S")
        answer = input()
        if answer == "w":
            room = 1
        elif answer == "s":
            room = 3
    elif room == 3:
        print ("you are in the Courtyard , you can go N or E")
        answer = input()
        if answer == "n":
            room = 2
        elif answer == "e":
            room = 4
    elif room == 4:
        print ("you are in the Cafeteria , you can go W or S or E")
        answer = input()
        if answer == "w":
            room = 3
        elif answer == "s":
            room = 5
        elif answer == "s":
            room = 6
    elif room == 3:
        print ("you are in the Courtyard , you can go N or E")
        answer = input()
        if answer == "n":
            room = 2

sf = open('save.txt', 'w')
sf.writelines(str(room))
sf.close()
