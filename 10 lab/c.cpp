#include <iostream>
#include <vector>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    vector<int> hist;
    int operations = 0;

    while (b != a) {
        hist.push_back(b);
        if (b % 2 == 0 && b > a) {
            b /= 2;
        } else {
            b++;  // Decrement b when it's odd or less than a
        }
        operations++;
    }

    // Output the number of operations
    cout << operations << endl;
    // Then print the sequence in reverse (since we built it backwards)
    for (auto it = hist.rbegin(); it != hist.rend(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}
