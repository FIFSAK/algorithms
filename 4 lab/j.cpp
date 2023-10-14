#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

vector<int> balancedBSTOrder(vector<int>& arr, int start, int end) {
    if (start > end) {
        return {};
    }

    int mid = start + (end - start) / 2;
    vector<int> leftOrder = balancedBSTOrder(arr, start, mid - 1);
    vector<int> rightOrder = balancedBSTOrder(arr, mid + 1, end);

    vector<int> order;
    order.push_back(arr[mid]);
    order.insert(order.end(), leftOrder.begin(), leftOrder.end());
    order.insert(order.end(), rightOrder.begin(), rightOrder.end());
    return order;
}

int main() {
    int N;
    cin >> N;
    N = pow(2, N)-1;
    vector<int> arr(N);
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }

    // Sort the array
    sort(arr.begin(), arr.end());

    // Get the order for a perfectly balanced BST
    vector<int> bstOrder = balancedBSTOrder(arr, 0, N - 1);

    // Print the result
    for (int val : bstOrder) {
        cout << val << ' ';
    }
    cout << endl;

    return 0;
}
