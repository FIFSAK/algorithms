#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int lower_bound(const vector<int>& arr, int value) {
    int l = 0, r = arr.size() - 1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (arr[mid] < value) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return l;
}

int upper_bound(const vector<int>& arr, int value) {
    int l = 0, r = arr.size() - 1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (arr[mid] <= value) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return r;
}

int main() {
    int size, rows;
    cin >> size >> rows;

    vector<int> arr(size);
    for (int i = 0; i < size; ++i) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());

    for (int i = 0; i < rows; ++i) {
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;

        int count1 = upper_bound(arr, r1) - lower_bound(arr, l1) + 1;
        int count2 = upper_bound(arr, r2) - lower_bound(arr, l2) + 1;

        // Adjust for overlap
        int overlap_start = max(l1, l2);
        int overlap_end = min(r1, r2);
        int overlap_count = 0;
        if (overlap_start <= overlap_end) {
            overlap_count = upper_bound(arr, overlap_end) - lower_bound(arr, overlap_start) + 1;
        }

        cout << count1 + count2 - overlap_count << endl;
    }

    return 0;
}
