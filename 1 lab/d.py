s = input()
stack = []
for i in s:
    if not stack or i !=stack[-1]:
        stack.append(i)
    else:
        stack.pop()
if not stack:
    print("YES")
else:
    print("NO")
