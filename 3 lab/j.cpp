#include <iostream>
#include <algorithm>
using namespace std;

bool canSteal(int mid, int arr[], int n, int f) {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        cnt += (arr[i] + mid - 1) / mid; 
        if (cnt > f) {
            return false;
        }
    }
    return true;
}

int main() {
    int n, hours;
    cin >> n >> hours;
    int arr[n];
    int totalgold = 0;
    int maxgold = 0;  
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        totalgold += arr[i];
        maxgold = max(maxgold, arr[i]);  
    }
    int l = totalgold / hours, r = maxgold, ans;  
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (canSteal(mid, arr, n, hours)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << ans;

    return 0;
}
