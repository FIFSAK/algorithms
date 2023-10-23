#include <iostream>
#include <vector>
#include <deque>
#include <map>
#include <algorithm>
using namespace std;


int findnum(const vector<int>& v, int x) {
    int l = 0;
    int r = v.size() - 1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (v[mid] == x) {
            return mid;  
        }
        if (x < v[mid]) {
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }
    return -1;  
}
void heapifydown(vector<int>& a, int n, int v){
    int mn = v;
    if(v*2+1<n && a[mn]<a[2*v+1]){
        mn = 2*v+1;
    }
    if(v*2+2<n && a[mn]<a[2*v+2]){
        mn = 2*v+2;
    }
    if(mn == v){
        return;
    }
    swap(a[mn], a[v]);
    heapifydown(a, n, mn);
}
void heapsort(vector<int>& a, int n){
    while(n>0){        
        swap(a[0], a[n]);
        heapifydown(a,n,0);
        n--;
    }
}

int main() {
    int n, m; cin >> n >> m;
    vector<int> v;
    vector<int> b;
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        v.push_back(a);
    }
    for (int i = 0; i < m; i++) {
        int a; cin >> a;
        b.push_back(a);
    }
    for (int i = v.size() / 2 - 1; i >= 0; i--) {
        heapifydown(v, v.size(), i);
    }
    heapsort(v, v.size() - 1);
    for (int i = 0; i < m; i++) {
        int index = findnum(v, b[i]);
        if (index != -1) {
            ans.push_back(v[index]);  
            v.erase(v.begin()+index);
        }
    }
     for (int i = ans.size() / 2 - 1; i >= 0; i--) {
        heapifydown(ans, ans.size(), i);
    }
    
    heapsort(ans, ans.size()-1);
    for(auto cur: ans){
        cout<<cur<<" ";
    }
    return 0;
}