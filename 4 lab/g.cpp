#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int v) : val(v), left(nullptr), right(nullptr) {}
};

struct BST {
    Node* root = nullptr;
    
    void insert(int val) {
        root = insert(root, val);
    }


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

    int getDiameter(Node* root, int &maxdiameter){
        // базовый случай: дерево пусто
        if (root == nullptr) {
            return 0;
        }
    
        // получаем высоты левого и правого поддеревьев
        int left_height = getDiameter(root->left, maxdiameter);
        int right_height = getDiameter(root->right, maxdiameter);
    
        // // вычисляем диаметр "сквозь" текущий узел
        int diameter = left_height + right_height + 1;
    
        // // обновить максимальный диаметр (обратите внимание, что диаметр "исключая" текущий
        // // узел в поддереве с корнем в текущем узле уже обновлен
        // // так как мы делаем обход в обратном порядке)
        maxdiameter = max(maxdiameter, diameter);
    
        // важно вернуть высоту поддерева с корнем в текущем узле
        return max(left_height, right_height) + 1;
    }

    int getDiameter(Node* root){
        int maxdiameter = 0;
        getDiameter(root, maxdiameter);
    
        return maxdiameter;
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

    cout << tree.getDiameter(tree.root)  << endl; 

    return 0;
}