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
    int n; cin>>n;
    vector<int> v;
    vector<char> vow;
    vector<char> notvow;

    map<char, int> vels = {{'a', 1}, {'e', 1}, {'i', 1}, {'o', 1}, {'u', 1}};
    for(int i = 0;i<n;i++){
        char a; cin>>a;
        v.push_back(a);
    }
    for(int i = v.size()/2-1;i>=0;i--){
        heapifydown(v, v.size(), i);
    }
    heapsort(v, v.size()-1);
    string s;
    for(int i = 0;i<v.size();i++){
        char temp = char(v[i]);
        if(vels[temp]){
            vow.push_back(temp);
        }
        else{
            notvow.push_back(temp);
        }
        
    }
    for(auto cur: vow){
        cout<<cur;
    }
    for(auto cur: notvow){
        cout<<cur;
    }
    return 0;
}
