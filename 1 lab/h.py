num = int(input())
if num == 1:
    print("NO")
cnt = 0
for i in range(1, num + 1):
    if cnt > 2:
        print("NO")
        exit()
    if num % i == 0:
        cnt += 1
if cnt == 2:
    print("YES")
else:
    print()
