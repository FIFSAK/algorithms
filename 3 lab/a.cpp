#include <iostream>
using namespace std;

int binarySearch(int **array, int x, int low, int high, int row) {
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (array[row][mid] == x) {
            return mid;
        }

        if (array[row][mid] < x)
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
            return mid;
        }
        if (array[row][mid] > x) 
            low = mid + 1;
        else
            high = mid - 1;
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
        bool found = false;
        for(int j = 0; j < n; j++) {
            int col;
            if(j % 2 == 1) {
                col = binarySearch(arr, target, 0, m-1, j);
            } else {
                col = binarySearchDecreasing(arr, target, 0, m-1, j);
            }
            if(col != -1) {
                cout << j << " " << col << endl;
                found = true;
                break;
            }
        }
        if(!found) {
            cout << "-1" << endl;
        }
    }

    // Free the dynamically allocated memory
    for(int i = 0; i < n; i++) {
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}
