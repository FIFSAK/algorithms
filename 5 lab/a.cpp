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
struct Heap {
    Node* root = nullptr;

    void insertLeft(int x) {
        if (root == nullptr) {
            root = new Node(x);
            return;
        }
        insertLeft(root, x);
    }

    void insertLeft(Node* cur, int x) {
        if (cur->left == nullptr) {
            cur->left = new Node(x);
            return;
            }
        insertLeft(cur->left, x);  
    }

    void insertRight(int x) {
        if (root == nullptr) {
            root = new Node(x);
            return;
        }
        insertRight(root, x);
    }

    void insertRight(Node* cur, int x) {
        if (cur->right == nullptr) {
            cur->right = new Node(x);
            return;
            }
        insertRight(cur->right, x);  
    }
};

int main() {

    return 0;
}