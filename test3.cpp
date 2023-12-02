#include <iostream>
#include <vector>

using namespace std;

int partition(vector<long long>& arr, long long low, long long high) {
    long long pivot = arr[high];
    long long i = (low - 1);

    for (long long j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quicksort(vector<long long>& arr, long long low, long long high) {
    if (low < high) {
        long long pivotIndex = partition(arr, low, high);
        quicksort(arr, low, pivotIndex - 1);
        quicksort(arr, pivotIndex + 1, high);
    }
}

int main() {
    long long n; cin>>n;

    vector<long long> arr(n);
    for(long long i = 0 ;i < n; i++){
        cin>>arr[i];
    }
    

    long long low = 0;
    long long high = arr.size() - 1;

    quicksort(arr, low, high);

    for (long long num : arr) {
        cout << num << " ";
    }

    return 0;
}
