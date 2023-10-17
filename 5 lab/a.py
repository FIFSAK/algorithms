a = [0]
global n
n = 0


def heapify_up(v):
    while v != 1 and a[v] > a[v // 2]:
        a[v], a[v // 2] = a[v // 2], a[v]
        v = v // 2


def push(x):
    global n;
    n += 1
    a.append(x)
    heapify_up(n)


def heapify_down(v):
    global n
    mx = v
    if 2 * v <= n and a[mx] < a[2 * v]: mx = 2 * v
    if 2 * v + 1 <= n and a[mx] < a[2 * v + 1]: mx = 2 * v + 1
    if mx == v:
        return
    heapify_down(mx)


def pop():
    global n
    a[1], a[n] = a[n], a[1]
    n -= 1
    heapify_down(a, n, 1)


def top():
    return a[1]


size = input()
arr = list(map(int, input().split()))
arr = [push(i) for i in arr]
print(a)