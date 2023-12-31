#include <iostream>
#include <vector>
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
    Node* find(Node *cur, int x) {
		if (x == cur->key)
			return cur;
		if (x < cur->key)
			return cur->left == NULL ? NULL : find(cur->left, x);
		// x > key
		return cur->right == NULL ? NULL: find(cur->right, x);
	}

	Node* find(int x) {
		return find(root, x);
	}

    int travel(Node* cur, int cnt){
        if(cur == nullptr){
            return cnt;
        }
        cnt = travel(cur->left, cnt);
        cnt = travel(cur->right, cnt);
        cnt++;
        return cnt;
    }   
    vector<int> preOrder(Node* cur){
        vector<int> res;
        preOrder(cur, res);
        return res;
    }
    void preOrder(Node* cur, vector<int>& res){
        if(cur==nullptr){
            return;
        }
        res.push_back(cur->key);
        preOrder(cur->left, res);
        preOrder(cur->right, res);
    }
};

int main() {
    int n; cin >> n;
    BST tree;
    for (int i = 0; i < n; i++) {
        int temp; cin >> temp;
        tree.insert(temp);
    }
    int target; cin>>target;
    Node* head = tree.find(target);
    vector<int> v=tree.preOrder(head);
    for(int i = 0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    return 0;
}