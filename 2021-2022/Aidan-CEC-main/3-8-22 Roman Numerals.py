r = input("Type a roman numeral \n -- ")

romandic = {"I":1,"V":5,"X":10,"L":50,"C":100,"D":500,"M":1000}

def roman(x):
    total = 0
    for i in range(len(x)):
        x[i]
        if i < len(x)-1:
            if x[i] == "I" and (x[i+1]=="V"or x[i+1]=="X"):
                total -= 1
            elif x[i] == "X" and (x[i+1]=="L"or x[i+1]=="C"):
                total -= 10
            elif x[i] == "C" and (x[i+1]=="D"or x[i+1]=="M"):
                total -= 100
            else:
                total += romandic.get(x[i])
        else:
            total += romandic.get(x[i])
    return total


print(roman(r))
