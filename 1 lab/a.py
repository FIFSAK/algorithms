def card(n: int) -> list:
    arr = [0] * n
    result = []
    for i in range(n, 0, -1):
        arr.append(i)
    i = 1
    cnt = n
    for i in arr:
        result.append(i)
        if len(result) > 1:
            while i < cnt:
                temp = result.pop()
                result.append(temp)
                i+=1
            i = 1
            cnt -= 1
    return result

print(card(5))

# test_cnt = int(input())
# tests = []
# for i in range(test_cnt):
#     a = int(input())
#     temp = [i for i in range(1, a + 1)]
#     tests.append(temp)
#
# for i in tests:
#     arr = i
#     temp = [0] * len(arr)
#     step = 1
#     start = 0
#     j = 0
#     while True:
#         start += step
#         temp[start] = arr[j]
#         j += 1
#         if start >= len(arr):
#             start = len(arr) - start
#         elif step == 2:
#             step = 1
#         elif step == 1:
#             step = 2


"""
[1, 2, 3, 4, 5]
 0  1  2  3  4
 
[1,2,3,4,5]

[2, 5, 4, 1, 3]
"""
