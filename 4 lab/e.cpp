#include <iostream>
#include <vector>
#include <map>
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

    void insert(int x, int y, int pos) {
        if (root == nullptr) {
            root = new Node(x);
            insert(root, y, pos);
            return;
        }
        insert(root, y, pos);

    }

    void insert(Node* cur, int x, int pos) {
        if (pos== 0) {
            cur->left = new Node(x);
            return;
        } 
        else {
            cur->right = new Node(x);
            return;
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
    int maxDepth(Node* cur, int depth, map<int, int>& res) {
        if (cur == nullptr) {
            return 0;
        }

        res[depth] += cur->key;

        int left = maxDepth(cur->left, depth + 1, res);
        int right = maxDepth(cur->right, depth + 1, res);

        return max(left, right) + 1;
    }

    void maxDepth() {
        map<int, int> res;
        int depth = maxDepth(root, 1, res);

        cout << depth << endl;
        for (auto i : res) {
            cout << i.second << " ";
        }
}

};

int main() {
    int n; cin >> n;
    BST tree;
    for (int i = 0; i < n-1; i++) {
        int x,y,z; cin >>x>>y>>z;
        if(i==0){
            tree.insert(x,y,z);
            continue;
        }
        Node* head = tree.find(x);
        tree.insert(head, y,z);
    }

    
    return 0;
}