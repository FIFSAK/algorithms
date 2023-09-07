s = input().split()
s2, s = s[1], s[0]


def backspace(s: list):
    for i in range(len(s)):
        if s[i] == "#":
            s.remove(i)
            s.remove(i-1)
    return "".join(s)


print(backspace(s))
print(backspace(s2))
