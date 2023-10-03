#include <iostream>
#include <algorithm>
using namespace std;

int binarysearch(int arr[], int value, int n){
    int l = 0, r = n -1;
    while (l<=r){
        int mid = l + (r-l)/2;
        if(arr[mid]>value){
            r = mid -1;
        }
        else{
            l = mid + 1;
        }
    }
    return l;
}

int main() {

    int n;
    cin >> n;
    int arr[n];
    int prefixSum[n] = {0}; // Initialize prefix sum array
    for (int i = 0; i < n; i++) {
        cin>>arr[i];
    }
    sort(arr, arr+n);

    // Build the prefix sum array
    prefixSum[0] = arr[0];
    for(int i = 1; i < n; i++) {
        prefixSum[i] = prefixSum[i-1] + arr[i];
    }

    int rounds; cin>>rounds;
    for(int i = 0; i<rounds;i++){
        int power; cin>>power;
        int cnt = binarysearch(arr, power, n);
        int sump = (cnt > 0) ? prefixSum[cnt-1] : 0; // Get the sum from prefix sum array
        cout << cnt << " " << sump << endl;
    }

    return 0;
}
