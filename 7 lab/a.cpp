#include <iostream>
#include <cassert>
#include <algorithm>
#include <vector>
using namespace std;

const int N = (int)1e5 + 7;

bool compare(string a, string b){
    if(a.size()==b.size()){
        return true;
    }
    return a.size()<=b.size();
}

void merge(vector<string>& a, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    vector<string> L(n1);
    vector<string> R(n2);

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


void mergeSort(vector<string>& arr, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}



int main() {
	int n; cin>>n;
    vector<string> v;
    for(int i = 0;i<n;i++){
        while(true){
            string temp;cin>>temp;
            v.push_back(temp);
            if (cin.peek() == '\n'){
               break;
            }
        }
        mergeSort(v, 0, v.size()-1);
         for(const string& s : v) {
            cout << s << " ";
        }
        cout<<endl;
        v.clear();
    }



	return 0;
}



