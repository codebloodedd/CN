def chararcterCountIn():
    s = str(input("Enter the data unit and to seperate 2 data units add a $ between them: "))
    arrayS = s.split("$")

    finalS = []
    for x in arrayS:
        finalS.append(x)
        finalS.append(str(len(x)))

    answer = "".join(finalS)
    answer = answer[:-1]
    print(answer)

def chararcterCountOut():
    str = input("Enter string: ")
    length = len(str)
    i = 0
    while i < length:
        print(i, end=" ")
        if str[i].isdigit():
            for j in range(i+1, i + int(str[i])+1):
                print(str[j], end ="")
            i = i + int(str[i])
        i = i+1
        print(i, end=" ")

def byteStuffing():
    s = input("Enter the data $ for flag and # for esc: ")
    length = len(s);
    arrayS = list(s)
    print(arrayS)
    for i in range (0, length):
        if arrayS[i] == "$":
            arrayS[i] = "$$"
        elif arrayS[i] == "#":
            arrayS[i] = "$#"
    
    arrayS.append("#")
    answer = "".join(arrayS)
    print(answer)

def byteDestuffing():
    s = input("Enter the data: ")
    length = len(s);
    arrayS = s.split("$$")

    print(arrayS)
    answer = "$".join(arrayS)
    print(answer)

def bitStuffing():
    s = input("Enter the data ")
    length = len(s)
    arrayS = s.split("11111")
    print(arrayS)
    answer = "111110".join(arrayS)
    print(answer)


# chararcterCountIn()
# chararcterCountOut()
# byteStuffing()
# byteDestuffing()
bitStuffing()