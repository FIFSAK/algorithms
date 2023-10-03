def canFly(mid, arr, n, f):
    cnt = 0
    for i in range(n):
        temp = arr[i]
        while temp > 0:
            temp -= mid
            cnt += 1
        if cnt > f:
            break
        cnt = 0
    return cnt <= f


def main():
    # n, f = map(int, input().split())
    # arr = list(map(int, input().split()))
    n = 3
    f = 6
    arr = [10, 10, 10]
    arr.sort()
    l, r = 0, arr[-1]
    ans = -1
    while l <= r:
        mid = l + (r - l) // 2
        if canFly(mid, arr.copy(), n, f):
            ans = mid
            r = mid - 1
        else:
            l = mid + 1
    print(ans)


if __name__ == "__main__":
    main()
