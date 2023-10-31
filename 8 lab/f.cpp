#include <iostream>
#include <set>
#include <string>
#include <unordered_set>

using namespace std;

const int p = 31;
const int m = 1e9 + 9;

void rk2(string s) {
    long long n = s.length();
    unordered_set <long long> d;
    for (long long i = 0; i < n; i++) {
        long long hs = 0;
        for (long long j = i; j < n; j++) {
            hs = (hs * p + (s[j] - 'a' + 1));
            d.insert(hs);
        }
    }

    cout << d.size();
}

int main() {
    string s; cin >> s;
    rk2(s);
}
