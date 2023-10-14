#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int v) : val(v), left(nullptr), right(nullptr) {}
};

class BST {
public:
    Node* root = nullptr;
    
    void insert(int val) {
        root = insert(root, val);
    }

    int diameter() {
        return diameter(root);
    }
private:
    Node* insert(Node* node, int val) {
        if (node == nullptr) {
            return new Node(val);
        }
        if (val < node->val) {
            node->left = insert(node->left, val);
        } else if (val > node->val) {
            node->right = insert(node->right, val);
        }
        return node;
    }

    int diameter(Node* node) {
        if (node == nullptr) return 0;

        int lHeight = height(node->left);
        int rHeight = height(node->right);

        int lDiameter = diameter(node->left);
        int rDiameter = diameter(node->right);

        return max(lHeight + rHeight + 1, max(lDiameter, rDiameter));
    }

    int height(Node* node) {
        if (node == nullptr) return 0;
        return 1 + max(height(node->left), height(node->right));
    }
};

int main() {
    int N;
    cin >> N;

    BST tree;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        tree.insert(x);
    }

    cout << tree.diameter()  << endl; 

    return 0;
}