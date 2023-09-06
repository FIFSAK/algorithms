test_cnt = int(input())
tests = []
for i in range(test_cnt):
    a = int(input())
    temp = [i for i in range(1, a+1)]
    tests.append(temp)

for i in tests:
    arr = i
    