test_cnt = int(input())
tests = []
for i in range(test_cnt):
    a = int(input())
    temp = [i for i in range(1, a + 1)]
    tests.append(temp)

for i in tests:
    arr = i
    temp = [0] * len(arr)
    step = 1
    start = 0
    j = 0
    while True:
        start += step
        temp[start] = arr[j]
        j += 1
        if start >= len(arr):
            start = len(arr) - start
        elif step == 2:
            step = 1
        elif step == 1:
            step = 2


"""
[1, 2, 3, 4, 5]
 0  1  2  3  4
 
[3, 1, 4, 5 ,2]
 0  1  2  3  4
 
[2, 1, 4, 3]
[2, 1, , ]
"""
