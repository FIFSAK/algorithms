#include <iostream>
#include <algorithm>
using namespace std;


bool canfit(int mid, int k, int arr[], int n){
    int cnt = 0;
    for(int i = 0; i<n; i++){
        if (arr[i]<=mid){
            cnt++;
        }
    }
    return cnt>=k;

}

int main() {

    int n, k;
    cin >> n >> k;
    int arr[n];
    int maxside = 0;
    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2; cin>>x1>>y1>>x2>>y2;
        arr[i] = max(max(x1, x2), max(y1, y2));
        if (arr[i]>maxside){
            maxside = arr[i];
        }
    }
    int ans = maxside;
    int l = 1, r = maxside;
    while (l<=r){
        int mid = l+(r-l)/2;
        if(canfit(mid, k, arr, n)){
            ans = mid;
            r = mid -1;
        }
        else{
            l = mid +1;
        }
    }
    cout<<ans;
    return 0;
}
