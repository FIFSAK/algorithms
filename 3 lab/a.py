def binary_search(matrix, x, low, high, row):
    while low <= high:
        mid = low + (high - low) // 2

        if matrix[row][mid] == x:
            print(row, mid)
            return True

        if matrix[row][mid] < x:  # Change this condition for descending order
            low = mid + 1
        else:
            high = mid - 1
    print(-1)
    return False


def binary_search_decreasing(matrix, x, low, high, row):
    while low <= high:
        mid = low + (high - low) // 2

        if matrix[row][mid] == x:
            print(row, mid)
            return True

        if matrix[row][mid] < x:
            high = mid - 1
        else:
            low = mid + 1
    print(-1)
    return False


def main():
    size_target = int(input())
    target_arr = list(map(lambda x: int(x), input().split()))
    n, m = map(int, input().split())
    matrix = [list(map(int, input().split())) for _ in range(n)]

    for i in range(size_target):
        flag = True
        target = target_arr[i]
        for j in range(n-1, -1, -1):
            if j % 2 == 1:
                if target >= matrix[j][0] and target <= matrix[j][m - 1]:
                    flag = binary_search(matrix, target, 0, m - 1, j)
                    break
            else:
                if target <= matrix[j][0] and target >= matrix[j][m - 1]:
                    flag = binary_search_decreasing(matrix, target, 0, m - 1, j)
                    break
        if not flag:
            print(-1)



if __name__ == "__main__":
    main()
