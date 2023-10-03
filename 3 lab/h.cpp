#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int arr[n];
    cin>>arr[0];
    for (int i = 1; i < n; i++) {
        int temp; cin >> temp;
        arr[i] = arr[i-1]+temp;
    }
    
    for(int i = 0;i<m;i++){
        int mis; cin>> mis;
        bool find = false;
        int l = 0, r = n-1; 
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if(mis == arr[mid]){
                cout<<mid+1;
                find = true;
                break;
            }
            else if(mis<arr[mid]){
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        if(!find){
            cout << l+1;
        }
        cout<<endl;
    }

    return 0;
}
