n, k = map(int, input().split())
arr = list(map(int, input().split()))

start, end, curr_sum, min_len = 0, 0, 0, float('inf')

while end < n:
    # Expand the current subarray
    curr_sum += arr[end]
    end += 1

    # Try to minimize the current subarray while maintaining the sum condition
    while curr_sum >= k:
        min_len = min(min_len, end - start)
        curr_sum -= arr[start]
        start += 1

print(min_len)
