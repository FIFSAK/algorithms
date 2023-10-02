houses, blocks = map(int, input().split())
arr = list(map(int, input().split()))

def canDivide(mid):
    count, curr_sum = 1, 0
    for i in arr:
        if curr_sum + i > mid:
            count += 1
            curr_sum = 0
        curr_sum += i
    return count <= blocks

low, high, ans = max(arr), sum(arr), -1
while low <= high:
    mid = (low + high) // 2
    if canDivide(mid):
        ans = mid
        high = mid - 1
    else:
        low = mid + 1

print(ans)
