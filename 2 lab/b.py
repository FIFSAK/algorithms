k = input().split()
n = int(k[0])
k = int(k[1])
s = input().split()

i = 0
cnt = 0
while cnt < n-k:
    if i >= len(s):
        i = 0
        while i < cnt:
            s[i], s[cnt] = s[cnt], s[i]
            i += 1
        cnt += 1
        i = cnt
    # temp = s[i+1]
    if i == 0:
        s[cnt], s[i + 1] = s[i + 1], s[i]
        i += 2
    else:
        s[cnt], s[i] = s[i], s[cnt]
        i += 1
print(" ".join(s))
