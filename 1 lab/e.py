bor = input().split()
nur = input().split()
bor = [int(i) for i in bor]
nur = [int(i) for i in nur]
cnt = 0
while nur and bor:
    b = bor.pop(0)
    n = nur.pop(0)
    if b == 0 and n == 9:
        bor.append(b)
        bor.append(n)
    elif n == 0 and b == 9:
        nur.append(b)
        nur.append(n)
    elif b > n:
        bor.append(b)
        bor.append(n)
    else:
        nur.append(b)
        nur.append(n)
    if cnt >= 1000000:
        break
    cnt += 1
if cnt >= 1000000:
    print("blin nichya")
elif bor:
    print("Boris", cnt)
elif nur:
    print("Nursik", cnt)
