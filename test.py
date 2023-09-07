size = int(input())
arr = []
result = [0] * size
for _ in range(size):
    arr.append(int(input()))
flag = True
for i in range(size):
    if i == 0:
        result[0] = -1
    for j in range(0, i, -1):
        if arr[j] < arr[i]:
            result[i] = arr[j]
            flag = False
    if flag:
        result[i] = -1

print(result)
