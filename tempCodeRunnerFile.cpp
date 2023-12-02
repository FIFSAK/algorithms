#include <iostream>
#include <vector>

using namespace std;


vector<int> merge(vector<int> a, int n, vector<int> b, int m){
    vector<int> res;
    int i = 0;
    int j = 0;
    while(i<n || j<m){
        if(i>=n){
            for(int z = j; z<m;z++){
                res.push_back(b[z]);
            }
            return res;
        }
        if(j>=m){
            for(int z = i; z<m;z++){
                res.push_back(a[z]);
            }
            return res;
        }
        if(a[i]<b[j]){
            res.push_back(a[i]);
            i++;
        }
        else{
            res.push_back(b[j]);
            j++;
        }
    }
    return res;
    
}

int main() {
    int n; cin>>n;
    vector<int> arr(n);
    for(int i = 0 ;i < n; i++){
        cin>>arr[i];
    }
    int m; cin>>m;
    vector<int> arr2(m);
    for(int i = 0 ;i < m; i++){
        cin>>arr2[i];
    }
    vector<int> res = merge(arr, n, arr2, m);
    for(auto cur: res){
        cout<<cur<<" ";
    }

    

    return 0;
}
