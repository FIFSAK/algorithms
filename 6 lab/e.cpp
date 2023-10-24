#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

void heapifydown(vector<int>& a, int n, int v){
    int mx = v;
    if(v*2+1<n && a[mx]>a[2*v+1]){
        mx = 2*v+1;
    }
    if(v*2+2<n && a[mx]>a[2*v+2]){
        mx = 2*v+2;
    }
    if(mx == v){
        return;
    }
    swap(a[mx], a[v]);
    heapifydown(a, n, mx);
}

void heapsort(vector<int>& a, int n){
    while(n>0){        
        swap(a[0], a[n]);
        heapifydown(a,n,0);
        n--;
    }
}
int main() {
    int n, m; 
    cin >> n >> m;

    vector<vector<int>> v(n, vector<int>(m));
    vector<vector<int>> res(m, vector<int>(n)); 

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> v[i][j];
        }
    }
    

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            res[j][i] = v[i][j];
        }
    }
    for(int j = 0;j<res.size();j++){
        for (int i = res[j].size() / 2 - 1; i >= 0; i--) {
            heapifydown(res[j], res[j].size(), i);
        }
        heapsort(res[j], res[j].size()-1);
    }
    for(int i = 0; i < n; i++){ 
        for(int j = 0; j < m; j++){ 
            cout << res[j][i] << " "; 
        }
        cout << endl;
    }



    return 0;
}





