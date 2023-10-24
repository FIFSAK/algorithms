#include <iostream>
#include <vector>
#include <string>
#include <iomanip> 
#include <algorithm>
#include <map>

using namespace std;

bool compare(string a, string b) {

    return a > b;
}

void heapifydown(vector<string>& strings, int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && compare(strings[l], strings[largest])) {
        largest = l;
    }

    if (r < n && compare(strings[r], strings[largest])) {
        largest = r;
    }

    if (largest != i) {
        swap(strings[i], strings[largest]);
        heapifydown(strings, n, largest);
    }
}

void buildHeap(vector<string>& strings, int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapifydown(strings, n, i);
    }
}

void heapsort(vector<string>& strings) {
    int n = strings.size();
    buildHeap(strings, n);

    for (int i = n - 1; i >= 0; i--) {
        swap(strings[0], strings[i]);
        heapifydown(strings, i, 0);
    }
}

int main() {
    int n; cin>>n;
    vector<string> v;
    for(int i = 0; i < n ;i++){
        string temp; cin>>temp;
        v.push_back(temp);
    }
    string s;cin>>s;
    heapsort(v);
    for(int i = 0;i<n;i++){
        if(v[i]>s){
            cout<<v[i];
            return 0;;
        }
    }
    cout<<v[0];
    
}