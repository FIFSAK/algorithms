#include <iostream>
#include <vector>
#include <map>
#include<algorithm>
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
        if(cur->left != nullptr and cur->right!=nullptr){
            cnt++;
        }
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
    void prefix(Node* cur, vector<int>& v){
        if(cur == nullptr){
            return;
        }
        prefix(cur->right, v);
        v.push_back(cur->key + v[v.size()-1]);
        prefix(cur->left, v);
    }
    vector<int> prefix(){
        vector <int> v;
        v.push_back(0);
        prefix(root, v);
        sort(v.begin(), v.end());
        return v;
    }

};

int main() {
    int n; cin >> n;
    BST tree;
    for (int i = 0; i < n; i++) {
        int temp; cin >> temp;
        tree.insert(temp);
    }
    vector<int> v = tree.prefix();
    for(int i = 0;i<v.size();i++){
        if(i!=0){
            cout<<v[i]<<" ";
        }
    }

    
    return 0;
}