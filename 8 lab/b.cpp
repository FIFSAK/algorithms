#include <iostream>
#include <vector>

using namespace std;

int get_hash(char a) {
    return a - 'a' + 1;
}

int sum(const vector<int>& v, int st, int end) {
    int s = 0;
    for(int i = st; i < end; i++) {
        s += v[i];
    }
    return s;
}

bool eq(const string& a, const string& target, int st, int end) {
    for(int i = st; i < end; i++) {
        if(a[i] != target[i - st]) {
            return false;
        }
    }
    return true;
}

int main() {
    string s; cin >> s;
    string s2; cin >> s2;
    string par; cin >> par;
    int par_h = 0;
    vector<int> s_h(s.size());
    vector<int> s2_h(s2.size());

    for(int i = 0; i < par.size(); i++) {
        par_h += get_hash(par[i]);
    }

    for(int i = 0; i<s.size(); i++){
        s_h[i] = get_hash(s[i]);
        s2_h[i] = get_hash(s2[i]);
    }

    int cnt = 0;
    for(int i = 0; i <= s.size() - par.size(); i++) {
        if(sum(s_h, i, i + par.size()) == par_h && sum(s2_h, i, i + par.size()) == par_h) {
            if(eq(s, par, i, i + par.size()) && eq(s2, par, i, i + par.size())) {
                cnt++;
            }
        }
    }
    cout << cnt;
    return 0;
}
