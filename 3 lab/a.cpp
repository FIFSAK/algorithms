#include <iostream>
using namespace std;

int binarySearch(int **array, int x, int low, int high, int row) {
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (array[row][mid] == x) {
            cout << row << " " << mid << endl;
            return mid;
        }

        if (array[row][mid] > x)  // Change this condition for descending order
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}
int binarySearchDecreasing(int **array, int x, int low, int high, int row) {
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (array[row][mid] == x) {
            cout << row << " " << mid << endl;
            return mid;
        }

        // Since the array is sorted in decreasing order,
        // if the current element is smaller than x, 
        // we move to the left part of the array.
        if (array[row][mid] < x) 
            high = mid - 1;
        else
            low = mid + 1;
    }

    return -1;
}

int main() {
    int size_target; cin >> size_target;
    int target_arr[size_target];
    for(int i = 0; i < size_target; i++) {
        cin >> target_arr[i];
    }

    int n, m; cin >> n >> m;
    int** arr = new int*[n];
    for(int i = 0; i < n; i++) {
        arr[i] = new int[m];
        for(int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < size_target; i++) {
        int target = target_arr[i];
        for(int j = 0; j < n; j++) {
            if(i%2==1) {
                if(target <= arr[j][m-1]) {
                    binarySearch(arr, target, 0, m-1, j);
                }
            } else {
                if(target <= arr[j][0]) {
                    binarySearchDecreasing(arr, target, 0, m-1, j);
                }
            }
        }
    }


    return 0;
}
