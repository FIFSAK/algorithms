#include <iostream>
using namespace std;

bool check(int mid, int arr[], int n, int k) {
    int sum = 0;
    for (int i = 0; i < mid; i++) {
        sum += arr[i];
    }
    if (sum >= k) return true;

    for (int i = mid; i < n; i++) {
        sum += arr[i] - arr[i - mid];
        if (sum >= k) return true;
    }
    return false;
}

int main() {
    int n, k;
    cin >> n >> k;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int l = 1, r = n, ans = n;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (check(mid, arr, n, k)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    cout << ans << endl;

    return 0;
}
/*
#include <iostream>
using namespace std;

bool check(int mid, int pref[], int n, int k) {
    for (int i = 0; i + mid <= n; i++) {
        int sum = pref[i + mid] - pref[i];
        if (sum >= k) {
            return true;
        }
    }
    return false;
}

int main() {
    int n, k;
    cin >> n >> k;

    int arr[n];
    int pref[n+1];
    pref[0] = 0;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i-1];
        pref[i] = arr[i-1] + pref[i - 1];
    }

    int l = 1, r = n, ans = n;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (check(mid, pref, n, k)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    cout << ans << endl;

    return 0;


}
*/