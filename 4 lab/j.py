def balanced_bst_order(arr):
    if not arr:  # Base case
        return []

    mid_idx = len(arr) // 2
    middle = arr[mid_idx]

    left_half = arr[:mid_idx]
    right_half = arr[mid_idx+1:]

    # Recursively get the order for the left and right halves
    left_order = balanced_bst_order(left_half)
    right_order = balanced_bst_order(right_half)

    # Combine and return the order
    return [middle] + left_order + right_order

def main():
    # Input
    N = int(input().strip())
    arr = list(map(int, input().split()))

    # Sort the array
    arr.sort()

    # Get the order for a perfectly balanced BST
    bst_order = balanced_bst_order(arr)

    # Print the result
    print(' '.join(map(str, bst_order)))

main()