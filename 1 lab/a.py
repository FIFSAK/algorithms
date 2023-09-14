def card(n: int) -> str:
    result = []
    cnt = n
    z = 1
    for i in range(n, 0, -1):
        result.append(str(i))
        if len(result) > 1:
            while z < cnt:
                temp = result[0]
                result.remove(temp)
                result.append(temp)
                z += 1
            z = 1
            cnt -= 1
    result = result[::-1]
    return ' '.join(result)



n = int(input())
for i in range(n):
    size = int(input())
    print(card(size))
