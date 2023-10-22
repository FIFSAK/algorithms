#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

void heapifydown(vector<int>& a, int n, int v){
    int mn = v;
    if(v*2+1<n && a[mn]>a[2*v+1]){
        mn = 2*v+1;
    }
    if(v*2+2<n && a[mn]>a[2*v+2]){
        mn = 2*v+2;
    }
    if(mn == v){
        return;
    }
    swap(a[mn], a[v]);
    heapifydown(a, n, mn);
}

int main() {
    int n; cin>>n;
    vector<int> vow;
    vector<int> notvow;
    map<char, int> vowels = {{'a', 1}, {'e', 1}, {'i', 1}, {'o', 1}, {'u', 1}};
    for(int i = 0;i<n;i++){
        char a; cin>>a;
        if (vowels[a]){
            vow.push_back(a);
        }
        else{
            notvow.push_back(a);
        }
    }
    for(int i = vow.size()/2-1;i>=0;i--){
        heapifydown(vow, vow.size(), i);
    }
    for(int i = notvow.size()/2-1;i>=0;i--){
        heapifydown(notvow, notvow.size(), i);
    }
    for(auto cur: vow){
        cout<<char(cur);
    }
    for(auto cur: notvow){
        cout<<char(cur);
    }
    return 0;
}
