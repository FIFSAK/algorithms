#include <iostream>
#include <cassert>
#include <algorithm>
#include <vector>
using namespace std;


void merge(vector<int>& a, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    vector<int> L(n1);
    vector<int> R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = a[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = a[m + 1 + j];

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            a[k] = L[i];
            i++;
        } else {
            a[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        a[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        a[k] = R[j];
        j++;
        k++;
    }
}


void mergeSort(vector<int>& arr, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}



int main() {
	int n, m;cin>>n;
    vector<int> v;
    for(int i = 0; i<n;i++){
        int temp; cin>>temp;
        v.push_back(temp);
    }
    cin>>m;
    vector<int> v2(m);
    for(int i = 0;i<m;i++){
        int temp; cin>>temp;
        v.push_back(temp);
    }
    
    mergeSort(v, 0, n+m-1);
    for(int i = 0;i<v.size();i++){
        cout<<v[i]<<" ";
    }

    
	return 0;
}



