def heapify(arr, n, i):
    largest = i
    l = 2 * i + 1  # left child
    r = 2 * i + 2  # right child

    # Check if left child exists and is greater than root
    if l < n and arr[i] < arr[l]:
        largest = l

    # Check if right child exists and is greater than the largest found so far
    if r < n and arr[largest] < arr[r]:
        largest = r

    # Change root if needed
    if largest != i:
        arr[i], arr[largest] = arr[largest], arr[i]

        # Heapify the root
        heapify(arr, n, largest)

def build_max_heap(arr):
    n = len(arr)

    # Start from the last parent node and work our way up to the root
    for i in range(n // 2 - 1, -1, -1):
        heapify(arr, n, i)

    return arr

def prefix_sum_from_heap(heap):
    prefix = [0] * len(heap)
    prefix[0] = heap[0]
    for i in range(1, len(heap)):
        prefix[i] = prefix[i-1] + heap[i]
    return prefix
    
# n = input()
# a = list(map(int, input().split()))
# a = build_max_heap(a)
a = [63, 29, 42, 26, 24, 15, 11, 18, 26, 19]
a.sort(reverse=True)
pref = [0]*(len(a)-1)
j = 1
pref[0]=a[len(a)-1]+a[len(a)-2]
for i in range(len(a)-3, -1, -1):
    pref[j]=a[i] + pref[j-1]
    j+=1
print(a)
print(pref)