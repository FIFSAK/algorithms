n = int(input())
arr = list(map(lambda x: int(x), input().split()))
k = int(input())
dist =  1000000
res = int()
for i in range(len(arr)):
    temp = abs(arr[i]-k)
    if temp<dist:
        dist = temp
        res = i
print(res)
