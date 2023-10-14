#include <iostream>
#include <vector>
#include <map>
using namespace std;

struct Node {
    Node* left;
    Node* right;
    int key;
    Node(int _key = 0) {
        left = right = NULL;
        key = _key;
    }
};

struct BST {
    Node* root = nullptr;

    void insert(int x) {
        if (root == nullptr) {
            root = new Node(x);
            return;
        }
        insert(root, x);
    }

    void insert(Node* cur, int x) {
        if (cur->key >= x) {
            if (cur->left == nullptr) {
                cur->left = new Node(x);
                return;
            }
            insert(cur->left, x);
        } else {
            if (cur->right == nullptr) {
                cur->right = new Node(x);
                return;
            }
            insert(cur->right, x);
        }
    }

    int dist = 0;

    int maxDepth(Node* cur) {
        if (cur == nullptr) {
            return 0;
        }

        int left = maxDepth(cur->left);
        int right = maxDepth(cur->right);
        
        // Update the maximum diameter
        dist = max(dist, left + right);
        
        return max(left, right) + 1;
    }

    int maxDepth() {
        maxDepth(root);
        return dist;
    }
};

int main() {
    int n; cin >> n;
    BST tree;
    for (int i = 0; i < n; i++) {
        int temp; cin >> temp;
        tree.insert(temp);
    }
    int maxd = tree.maxDepth();
    cout << maxd+1 << endl;
    
    return 0;
}
