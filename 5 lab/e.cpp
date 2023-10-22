#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 1e5 + 5;
long long heap[MAXN];
int heapSize = 0;

void push(long long value) {
    heap[++heapSize] = value;
    int i = heapSize;
    while (i > 1 && heap[i] < heap[i / 2]) {
        swap(heap[i], heap[i / 2]);
        i /= 2;
    }
}

long long top() {
    return heap[1];
}

void pop() {
    heap[1] = heap[heapSize--];
    int i = 1;
    while (true) {
        int j = i;
        if (2 * i <= heapSize && heap[2 * i] < heap[j]) {
            j = 2 * i;
        }
        if (2 * i + 1 <= heapSize && heap[2 * i + 1] < heap[j]) {
            j = 2 * i + 1;
        }
        if (i == j) {
            break;
        }
        swap(heap[i], heap[j]);
        i = j;
    }
}

int main() {
    int q, k;
    cin >> q >> k;
    
    while (q--) {
        string cmd;
        cin >> cmd;

        if (cmd == "insert") {
            long long n;
            cin >> n;

            if (heapSize < k) {
                push(n);
            } else if (n > top()) {
                pop();
                push(n);
            }
        } else if (cmd == "print") {
            long long sum = 0;
            for (int i = 1; i <= heapSize; i++) {
                sum += heap[i];
            }
            cout << sum << endl;
        }
    }

    return 0;
}