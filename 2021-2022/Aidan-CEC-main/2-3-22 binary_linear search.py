import random

class var():
    count1 = 0
    count2 = 0

    total1 = 0
    total2 = 0

def linearSearch(searchItem):
    for x in range (len(myList)):
        var.count1 += 1
        if myList[x] == int(searchItem):
            print (f"Your item is at index position {x}")
            var.total1 += 1
    if var.total1 == 0:
        print("Your number isn't here!")



def recursiveBinarySearch(unique_list, low, high, x):
    var.count2 += 1
    if high >= low:
        mid = (high + low) // 2
        if unique_list[mid] == x:
            var.total2 += 1
            print("Your number is at index position" + f" {mid}")
            return mid
        elif unique_list[mid] > x:
            return recursiveBinarySearch(unique_list, low, mid - 1, x)
        else:
            return recursiveBinarySearch(unique_list, mid + 1, high, x)
    else:
        print("Your number isn't here! Have you sorted your list?")


while True:

    myList = []

    for x in range(1,101):
        myList.append(random.randint(1,50))

    search = random.randint(1,50)
    myList.sort()

    y = input("Would you like to do a (R)ecursive Binary Search or a (L)inear Search? \n -- ")
    print("We are searching for the number ", search, "\n")

    if y.lower() == "r":
        recursiveBinarySearch(myList, 0, len(myList)-1, int(search))
        print("# of time run", var.count2)
        print("# of time found",var.total2)

    elif y.lower() == "l":
        linearSearch(int(search))
        print("# of time run",var.count1)
        print("# of time found",var.total1)

    quit = input("Would you like to go again? Y/N \n -- ")

    if quit.lower() == "n":
        break
    else:
        pass
