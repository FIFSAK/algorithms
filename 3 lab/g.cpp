// #include <iostream>
// #include <algorithm>
// using namespace std;



// bool canFly(int mid, int arr[], int n, int f) {
//     int cnt = 0;
//     for (int i = 0; i < n; i++) {
//         cnt += (arr[i] + mid - 1) / mid;  
//         if (cnt > f) {
//             return false;
//         }
//     }
//     return true;
// }

// int main() {
//     int n, f;
//     cin >> n >> f;
//     int arr[n];
//     for (int i = 0; i < n; i++) {
//         cin>>arr[i];
//     }
//     sort(arr, arr+n);
//     int l = 0, r = arr[n-1], ans = -1;
//     while (l<=r){
//         int mid = l + (r-l)/2;
//         if(canFly(mid, arr, n, f)){
//             ans = mid;
//             r = mid -1;
//         }
//         else{
//             l = mid + 1;
//         }
        
//     }
//     cout<<ans;

//     return 0;
// }

#include <iostream>
#include <algorithm>
using namespace std;

bool canFly(int mid, int arr[], int n, int f) {
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
    int n, f;
    cin >> n >> f;
    int arr[n];
    int totalChildren = 0;  
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        totalChildren += arr[i];
    }
    int l = 1, r = totalChildren, ans = -1;  
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (canFly(mid, arr, n, f)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << ans;

    return 0;
}
