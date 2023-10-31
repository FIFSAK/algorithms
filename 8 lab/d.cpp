#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int mod = 1e9 + 7;
int p = 31;

int get_hash(string s) {
    int h = 0;
    for (int i = 0; i < s.size(); i++) {
        h = h * p + (s[i] - 'a' + 1);
    }
    return h;
}

int rk(string s, string t) {
    int n = s.length(), m = t.length();
    int hs = get_hash(s.substr(0, m));
    int ht = get_hash(t);
    int pm = 1;
    for (int i = 0; i < m - 1; i++) {
        pm *= p;
    }
    int cnt = 0;
    for (int i = 0; i + m <= n; i++) {
        if (hs == ht) {
            cnt++;
        }
        if (i + m < n)
            hs = (hs - pm * (s[i] - 'a' + 1)) * p + (s[i + m] - 'a' + 1);
    }
    return cnt;
}

int main() {
    while (true) {
        int n; cin >> n;
        if (n == 0) break;

        vector<string> v(n);
        vector<string> res;
        for(int i = 0; i < n; i++){
            cin >> v[i];
        }
        string s; cin >> s;

        int mx = -2;
        int max_count = 0;
        for(int i = 0; i < n; i++) {
            int count = rk(s, v[i]);
            if (count > mx) {
                mx = count;
                max_count = count;
                res.clear();
                res.push_back(v[i]);
            } else if (count == mx) {
                res.push_back(v[i]);
            }

        }

        cout << max_count << endl;
        for(auto cur: res) {
            cout << cur << endl;
        }
    }
}
