size = int(input())
arr = input().split()
arr = [int(i) for i in arr]
result = [0] * size
flag = True
for i in range(size):
    for j in range(i-1, -1, -1):
        if arr[j] <= arr[i]:
            result[i] = arr[j]
            flag = False
            break
    if flag:
        result[i] = -1
    flag = True
for i in result:
    print(i,end=" ")
