#include <iostream>
#include <vector>
using namespace std;

void firstNonRepeating(int n, vector<string>& arr) {
    for (int i = 0; i < n; i++) {
        int j = 0;
        bool found = false;
        while (j <= i) {
            bool isUnique = true;
            for (int k = 0; k <= i; k++) {
                if (arr[k] == arr[j] && k != j) {
                    isUnique = false;
                    break;
                }
            }
            if (isUnique) {
                cout << arr[j] << " ";
                found = true;
                break;
            }
            j++;
        }
        if (!found) {
            cout << "-1 ";
        }
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<string> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        firstNonRepeating(n, arr);
    }
    return 0;
}
