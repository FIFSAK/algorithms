#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const long long N = (long long)1e5 + 7;

void heapify_up(long long *a, long long n, long long v) {
    while(v != 1 && a[v] < a[v/2]) {
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
    long long mn = v;
    if (2 * v <= n && a[mn] > a[2 * v]) mn = 2 * v;
    if (2*v+1 <= n && a[mn] > a[2*v+1]) mn = 2*v+1;
    if (mn == v)
        return;
    swap(a[mn], a[v]);
    heapify_down(a, n, mn);
}

long long pop(long long *a, long long &n) {
    long long top = a[1];
    swap(a[1], a[n]);
    n--;
    heapify_down(a, n, 1);
    return top;
}

long long getMinimumCost(vector<long long>& lengths) {  
    long long a[N];
    long long n = lengths.size();
    for(long long i = 0; i < n; i++) {
        a[i+1] = lengths[i];
    }
    
    for(long long i = n/2; i >= 1; i--) {
        heapify_down(a, n, i);
    }

    long long cost = 0;
    while (n > 1) {
        long long c = pop(a, n);  
        long long b = pop(a, n);  
        cost += c + b;
        push(a, n, c + b);
    }
    return cost;
}

int main() {
    long long n;
    cin >> n;
    vector<long long> lengths(n);  

    for (int i = 0; i < n; i++) {
        cin >> lengths[i];
    }

    cout << getMinimumCost(lengths) << endl;

    return 0;
}
