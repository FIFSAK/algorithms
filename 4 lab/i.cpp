#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

struct Node{
    Node* left;
    Node* right;
    int key;
    int cnt;
    Node(int _key = 0, int _cnt = 0) {
        left = right = NULL;
        key = _key;
        cnt = _cnt;
    }
};

struct BST {
    Node* root = nullptr;

    void insert(int x) {
        if (root == nullptr) {
            root = new Node(x, 1);
            return;
        }
        insert(root, x);
    }

    void insert(Node* cur, int x) {
        if (cur->key == x){
            if (cur->cnt == 0) {
                cur->cnt = 1;
            } else {
                cur->cnt++;
            }
            return;
        }
        else if (cur->key > x) {
            if (cur->left == nullptr) {
                cur->left = new Node(x, 1);
                return;
            }
            insert(cur->left, x);
        } 
        else {
            if (cur->right == nullptr) {
                cur->right = new Node(x, 1);
                return;
            }
            insert(cur->right, x);
        }
    }

    Node* find(Node *cur, int x) {
        if (!cur) return nullptr;
        if (x == cur->key) return cur;
        if (x < cur->key) return find(cur->left, x);
        return find(cur->right, x);
    }

    Node* find(int x) {
        Node* cur = find(root, x);
        if (cur && cur->cnt == 0) {
            return nullptr;
        }
        return cur;
    }

    void remove(int x) {
        root = remove(root, x);
    }

    Node* remove(Node* cur, int x) {
        if (!cur) return nullptr;

        if (x < cur->key) {
            cur->left = remove(cur->left, x);
        } else if (x > cur->key) {
            cur->right = remove(cur->right, x);
        } else {
            if (cur->cnt > 1) {
                cur->cnt--;
                return cur;
            } else {
                cur->cnt = 0;
            }
            
            if (!cur->left) {
                Node* temp = cur->right;
                delete cur;
                return temp;
            } else if (!cur->right) {
                Node* temp = cur->left;
                delete cur;
                return temp;
            }

            Node* temp = minValueNode(cur->right);
            cur->key = temp->key;
            cur->cnt = temp->cnt;
            temp->cnt = 1;
            cur->right = remove(cur->right, temp->key);
        }
        return cur;
    }

    Node* minValueNode(Node* cur) {
        Node* current = cur;
        while (current && current->left) {
            current = current->left;
        }
        return current;
    }   
};

int main() {
    int n; cin >> n;
    BST tree;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        int temp; cin >> temp;
        if (s == "insert") {
            tree.insert(temp);
        }
        if (s == "cnt") {
            Node* cur = tree.find(temp);
            if (cur == nullptr) {
                cout << 0 << endl;
            } else {
                cout << cur->cnt << endl;
            }
        }
        if (s == "delete") {
            tree.remove(temp);
        }
    }
    return 0;
}
