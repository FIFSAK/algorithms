n = int(input())

a = dict()

def has(n):
    res = 0
    for i in range(len(n)):
        ass = ord(n[i])
        res+=(ass-47)*pow(11, i)
    return res%(1000000000+7)


all = []
for i in range(n*2):
    temp = input()
    all.append(temp)
    a[temp] = str(has(temp))

for i in all:
    if a[i] in all:
        print(f'Hash of string "{i}" is {a[i]}')