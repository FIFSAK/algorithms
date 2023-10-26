#include <iostream>
#include <cassert>
#include <algorithm>
#include <vector>
using namespace std;

struct nums
{
    int sum;
    vector<int> v;
};

bool compare(nums a, nums b){
    if (a.sum == b.sum){
        return a.v <= b.v;
    }

    return a.sum > b.sum;
}

void merge(vector<nums>& a, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    vector<nums> L(n1);
    vector<nums> R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = a[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = a[m + 1 + j];

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        if (compare(L[i], R[j])) {
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


void mergeSort(vector<nums>& arr, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}



int main() {
	int n, m;cin>>n>>m;
    vector<nums> v;
    for(int i = 0; i<n;i++){
        vector<int> temp;
        int sum = 0;
        for(int j = 0;j<m;j++){
            int t;cin>>t;
            sum+=t;
            temp.push_back(t);
        }
        nums n;
        n.v = temp;
        n.sum = sum;
        v.push_back(n);
    }
    mergeSort(v, 0, v.size()-1);
    for(auto cur: v){
        for(auto j: cur.v){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    
    
	return 0;
}



