n = int(input())
s = list(input())
i = 0
flag = None
if n<100:
    while "S" in s and "K" in s:
        if s[i] == "K" and flag == "s":
            s[i] = ""
        elif s[i] == "S" and flag == "k":
            s[i] = ""
        elif s[i] == "S":
            flag = "s"
        elif s[i] == "K":
            flag = "k"

        if i == len(s) - 1:
            i = 0
        i += 1

    if "S" in s:
        print("SAKAYANAGI")
    else:
        print("KATSURAGI")
else:
    if s.count("K")>s.count("S"):
        print("KATSURAGI")
    elif s.count("K")<s.count("S"):
        print("SAKAYANAGI")
    else:
        if s[0] == "K":
            print("KATSURAGI")
        else:
            print("SAKAYANAGI")


