def push(a, x):
    a.append(x)
    heapify_up(a)
def heapify_up(a):
    n = len(a)
    v = n - 1  # Python arrays are 0-indexed
    while v > 0 and a[v] < a[(v - 1) // 2]:
        a[v], a[(v - 1) // 2] = a[(v - 1) // 2], a[v]
        v = (v - 1) // 2

def heapify(a, n, i):
    smallest = i
    l = 2 * i + 1
    r = 2 * i + 2
    
    if l < n and a[i] > a[l]:
        smallest = l
    if r < n and a[smallest] > a[r]:
        smallest = r
    if smallest != i:
        a[i], a[smallest] = a[smallest], a[i]
        heapify(a, n, smallest)

def build_heap(a):
    n = len(a)
    start_idx = n // 2 - 1
    for i in range(start_idx, -1, -1):
        heapify(a, n, i)

def getMinimumCost(lengths):
    build_heap(lengths)
    cost = 0
    while len(lengths) > 1:
        # Extract the two smallest values
        smallest = pop(lengths)
        second_smallest = pop(lengths)
        # Add to cost
        cost += (smallest + second_smallest)
        # Push merged value back to the heap
        push(lengths, smallest + second_smallest)
    return cost

def pop(a):
    n = len(a)
    top = a[0]
    a[0] = a[n-1]
    a.pop()
    if len(a) > 0:
        heapify(a, len(a), 0)
    return top

if __name__ == "__main__":
    n = int(input())
    lengths = list(map(int, input().split()))
    print(getMinimumCost(lengths))

