#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

long long mod = 1e9 + 7;
long long p = 31;

char reverseHash(long long hashValue, long long i) {
    return (hashValue / (long long)pow(2, i)) + 97;
}

int main() {
    long long n;cin>>n;
    vector<string> v(n);
    string s = "";
    long long prev;cin>>prev;
    s += reverseHash(prev, 0);
    for(long long i = 1; i < n; i++){
        long long temp;cin>>temp;
        temp -= prev;
        s+=reverseHash(temp, i);
        prev += temp;
        
    }
    cout<<s;

       
}
