import random

num1 = 3
while(num1<=21):
    print(num1, end = ' ')
    num1 += 3

print(" ")

inp = int(input("Type a number \n --"))
x = 1

while(x<=inp):
    print("SNURFLE")
    x+=1

Monster = 0
def MonsterGen(biome, x):
    if biome.lower() == "d":
        if x <= 2:
            print("A Husk Spawned")
            Monster = 1
        elif x <= 5:
            print("A Spider Spawned")
            Monster = 2
        else:
            print("A Skeleton Spawned")
            Monster = 3
    if biome.lower() == "f":
        if x <= 3:
            print("A Zombie Spawned")
            Monster = 4
        elif x <= 6:
            print("A Skeleton Spawned")
            Monster = 3
        elif x <= 7:
            print("A Witch Spawned")
            Monster = 1
        else:
            print("Nothing Spawned")
            Monster = 0


ramp = random.randint(1,10)
inp2 = input("Which Biome (d)esert or (f)eild \n -- ")
MonsterGen(inp2, ramp)
