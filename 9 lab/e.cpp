#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        int k;
        cin >> s >> k;

        // Compute the length of the longest proper prefix which is also a suffix
        int n = s.size();
        vector<int> lps(n, 0);
        for (int i = 1, len = 0; i < n;) {
            if (s[i] == s[len]) {
                lps[i++] = ++len;
            } else if (len) {
                len = lps[len - 1];
            } else {
                i++;
            }
        }

        int patternLength = n - lps[n - 1];
        int requiredLength = n + (k - 1) * patternLength;

        cout << requiredLength << endl;
    }
}