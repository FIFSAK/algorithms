a = [0] * 100
front, back = 50, 49
while True:
    method = input().split()
    if not method:
        continue
    if method[0] == "!":
        break
    if method[0] == "+":
        front -= 1
        a[front] = int(method[1])
    elif method[0] == "-":
        back += 1
        a[back] = int(method[1])
    elif method[0] == "*":
        if front < back:
            print(a[front] + a[back])
            a[front] = 0
            a[back] = 0
            front += 1
            back -= 1
        elif front == back:
            print(a[front] + a[back])
            a[front] = 0
            a[back] = 0
        else:
            print("error")
