size, rows = map(int, input().split())
arr = list(map(int, input().split()))
for i in range(rows):
    cnt = 0
    l1, r1, l2, r2 = map(int, input().split())
    for i in arr:
        if l1<=i<=r1 or l2<=i<=r2:
            cnt+=1
    print(cnt)