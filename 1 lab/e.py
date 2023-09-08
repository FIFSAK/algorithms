bor = input().split()
nur = input().split()
bor = [int(i) for i in bor]
nur = [int(i) for i in nur]
while nur and bor:
    b = bor.pop(0)
    n = nur.pop(0)
    
    if b > n:
        bor.append(b)
        bor.append(n)
    else:
        nur.append(b)
        nur.append(n)
    print('bor=', bor)
    print('nur=', nur)
