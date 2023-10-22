#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const long long N = (long long)1e5 + 7;

void heapify_up(long long *a, long long n, long long v) {
    while(v != 1 && a[v] > a[v/2]) {
        swap(a[v], a[v/2]);
        v = v / 2;
    }
}

void push(long long *a, long long &n, long long x) {
    n++;
    a[n] = x;
    heapify_up(a, n, n);
}

void heapify_down(long long *a, long long n, long long v) {
    long long mx = v;
    if (2 * v <= n && a[mx] < a[2 * v]) mx = 2 * v;
    if (2*v+1 <= n && a[mx] < a[2*v+1]) mx = 2*v+1;
    if (mx == v)
        return;
    swap(a[mx], a[v]);
    heapify_down(a, n, mx);
}

long long pop(long long *a, long long &n) {
    long long top = a[1];
    swap(a[1], a[n]);
    n--;
    heapify_down(a, n, 1);
    return top;
}

long long getRock(vector<long long>& lengths, long long x) {  
    long long a[N];
    long long n = lengths.size();
    for(long long i = 0; i < n; i++) {
        a[i+1] = lengths[i];
    }

    
    for(long long i = n/2; i >= 1; i--) {
        heapify_down(a, n, i);
    }
    

    long long cost = 0;
    while (x > 0) { 
        long long c = pop(a, n);  
        cost += c;
        c--;
        x--;
        push(a, n, c);
        
    }
    return cost;
}

int main() {
    long long n, x;
    cin >> n>> x;
    vector<long long> lengths(n);  

    for (int i = 0; i < n; i++) {
        cin >> lengths[i];
    }

    cout << getRock(lengths, x) << endl;

    return 0;
}
