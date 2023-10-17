n = input()
arr = list(map(int, input().split()))
pref = []
arr.sort()


def heap(arr):
    for i in range(len(arr)):
        l = 2 * i + 1
        r = 2 * i + 2
        if l < len(arr) and arr[l] < arr[i]:
            arr[l], arr[i] = arr[i], arr[l]
        if r < len(arr) and arr[r] < arr[i]:
            arr[l], arr[i] = arr[i], arr[l]
    return arr


pref = []
while len(arr) != 1:
    arr = heap(arr)
    if len(arr)>2:
        if arr[1]>arr[2]:
            arr[0] = arr[0] + arr[2]
            del arr[2]
            continue
        if arr[2]>arr[1]:
            arr[0] = arr[0] + arr[1]
            del arr[1]
            continue
    else:
        arr[0]= arr[0]+ arr[1]
        del arr[1]
    pref.append(arr[0])
    arr = heap(arr)

print(sum(pref))