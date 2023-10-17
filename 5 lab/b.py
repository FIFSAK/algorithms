def heapify(arr, n, i):
    largest = i  # Индекс текущего элемента
    left = 2 * i + 1  # Индекс левого потомка
    right = 2 * i + 2  # Индекс правого потомка

    # Если левый потомок существует и больше текущего элемента
    if left < n and arr[left] > arr[largest]:
        largest = left

    # Если правый потомок существует и больше текущего элемента
    if right < n and arr[right] > arr[largest]:
        largest = right

    # Если наибольший элемент не является текущим элементом
    if largest != i:
        arr[i], arr[largest] = arr[largest], arr[i]  # Обмен элементов
        heapify(arr, n, largest)  # Рекурсивно "heapify" поддерево

def rock(arr):
    if len(arr)==1:
        return arr
    l = 2+1
    r = 2+2
    if arr[l]>arr[r]:
        arr[0]=arr[0]-arr[l]
        del arr[l]
    else:
        arr[0]=arr[0]-arr[r]
        del arr[r]
    build_max_heap(arr)
    rock(arr)


def build_max_heap(arr):
    n = len(arr)

    # Начинаем с последнего элемента, который имеет потомков
    # и перемещаемся вверх по дереву
    for i in range(n // 2 - 1, -1, -1):
        heapify(arr, n, i)

    return arr

n = int(input())
arr = list(map(int, input().split()))

result = build_max_heap(arr)
print(rock(result))
