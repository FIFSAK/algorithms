#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int x; cin>>x;
    int l = 0, r = n-1;
    bool find = false;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if(x == arr[mid]){
            find = true;
            break;
        }
        else if(x<arr[mid]){
            r = mid-1;
        }
        else{
            l = mid+1;
        }
    }
    if(find){
        cout << "Yes";
    }
    else{
        cout<<"No";
    }
    

    return 0;
}
