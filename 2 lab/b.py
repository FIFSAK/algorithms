k = input().split()
n = int(k[0])
k = int(k[1])
s = input().split()

i = 0
cnt = 0
while cnt <= k:
    if i < len(s):
        i = 0
        cnt += 1
    # temp = s[i+1]
    if i == 0:
        s[0], s[i + 1] = s[i + 1], s[i]
        i += 2
    else:
        s[0], s[i] = s[i], s[0]
        i += 1
print(s)
