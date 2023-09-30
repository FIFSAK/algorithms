#include <iostream>
#include <vector>
#include <string>

using namespace std;
int main() {
    int N;
    cin >> N;
    vector<string> arr;

    string cname;
    string pname;

    for (int i = 0; i < N; i++) {
        cin >> cname;

        if (i == 0 || cname != pname) {
            arr.push_back(cname);
        }

        pname = cname;
    }

    cout << "All in all: " << arr.size() << endl;
    cout << "Students:" << endl;
    for (int i = arr.size() - 1; i >= 0; i--) {
        cout << arr[i] << endl;
    }

    return 0;
}