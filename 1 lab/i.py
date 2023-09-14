n = int(input())
s = input()
i = 0
flag = None
while "S" in s == False or "K" in s == False:
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
