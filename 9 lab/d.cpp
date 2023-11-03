#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int LPS (string hay, int m, string s) {
    vector <int> lps(m, 0);
    int len = 0;
    int i = 1;
    while (i < m) {
        if (s[i] == hay[len]) {
            lps[i] = len + 1;
            len++;
            i++;
        }
        else if (len != 0) {
            len = lps[len - 1];
        }
        else {
            i++;
        }
    }
    int res = lps[m - 1];
    return res;
}

int main() {
    string s; cin >> s;
    s[0] = tolower(s[0]);
    int n; cin >> n;
    int max = -1;
    vector<string> list;
    for (int i = 0; i < n; i++) {
        string t; cin >> t;
        string tmp = t;
        tmp[0] = tolower(t[0]);
        int length = LPS(tmp, s.size(), s);
        if (max < length) {
            list.clear();
            max = length;
            list.push_back(t);
        }
        else if (max == length) {
            list.push_back(t);
        }
    }
    if (max == 0) {
        cout << 0;
        return 0;
    }
    cout<<list.size()<<endl;
    for(auto cur: list){
        cout<<cur<<endl;
    }
}