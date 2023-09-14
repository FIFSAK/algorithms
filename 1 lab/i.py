n = int(input())
s = input()
i = 0
flag = None
while "S" in s == False or "K" in s == False:
    if s[i] == "K" and flag == "s":
        
    if s[i] == "S":
        flag = "s"
    if s[i] == "K":
        flag = "k"


    if i==len(s)-1:
        i = 0
    i+=1