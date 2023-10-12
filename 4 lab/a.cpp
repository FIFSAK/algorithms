#include <iostream>
using namespace std;

struct Node{
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
};

int main() {
    int n; cin >> n;
    int m; cin >> m;
    BST tree;
    for (int i = 0; i < n; i++) {
        int temp; cin >> temp;
        tree.insert(temp);
    }
    for (int i = 0; i < m; i++) {
        string s; cin >> s;
        Node* cur = tree.root;
        for (int j = 0; j < s.size() && cur != nullptr; j++) {
            if (s[j] == 'R') {
                cur = cur->right;
            } else if (s[j] == 'L') {
                cur = cur->left;
            }
        }
        if (cur != nullptr) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}