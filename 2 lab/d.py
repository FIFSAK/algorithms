n = int(input())
arr = list(map(lambda x: int(x), input().split()))
res = []
cnt = 0
max_mode = 0


for i in range(len(arr)):
    for j in range(len(arr)):
        if arr[i] == arr[j]:
            cnt+=1
    if max_mode < cnt:
        max_mode = cnt
        res = []
        res.append(arr[i])
    elif max_mode == cnt and arr[i] not in res:
        res.append(arr[i])
    cnt = 0
res.sort(reverse=True)
print(' '.join(map(str, res)))