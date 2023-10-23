#include <iostream>
#include <vector>
#include <deque>
#include <map>
#include <algorithm>
using namespace std;


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
    int n; cin >> n;
    vector<int> v;
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        v.push_back(a);
    }
    for (int i = v.size() / 2 - 1; i >= 0; i--) {
        heapifydown(v, v.size(), i);
    }
    heapsort(v, v.size()-1);
    int mindif = 1000000000;
    int a, b;
    for(int i = 0;i<v.size()-1;i++){
        int dif = abs(v[i]-v[i+1]);
        if(mindif == dif){
            a = v[i];
            b = v[i+1];
            ans.push_back(a);
            ans.push_back(b);
            mindif = dif;
        }
        else if (mindif>dif){
            ans.clear();
            a = v[i];
            b = v[i+1];
            ans.push_back(a);
            ans.push_back(b);
            mindif = dif;
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