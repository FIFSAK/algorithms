#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

struct Node {
    Node* left;
    Node* right;
    long long key;  
    Node(long long _key = 0) {  
        left = right = nullptr;
        key = _key;
    }
};

struct Heap {
    Node* root = nullptr;
    vector<Node*> nodes; // Список всех узлов
    
    // Вставка нового элемента
    void insert(long long x) {  
        Node* newNode = new Node(x);
        nodes.push_back(newNode);

        if (!root) {
            root = newNode;
            return;
        }

        Node* parent = root;
        // Определение позиции нового узла в куче
        for (int i = log2(nodes.size()); i > 0; i--) {
            if ((nodes.size() >> (i - 1)) & 1) {
                if (i == 1) parent->right = newNode;
                else parent = parent->right;
            } else {
                if (i == 1) parent->left = newNode;
                else parent = parent->left;
            }
        }

        bubbleUp(nodes.size() - 1);
    }

    void bubbleUp(int idx) {
        if (idx == 0) return;
        int parentIdx = (idx - 1) / 2;
        if (nodes[idx]->key < nodes[parentIdx]->key) {
            swap(nodes[idx]->key, nodes[parentIdx]->key);
            bubbleUp(parentIdx);
        }
    }

    // Удаление минимального элемента
    long long pop() {  
        if (!root) return -1;

        long long minValue = root->key;  
        int lastIdx = nodes.size() - 1;

        swap(root->key, nodes[lastIdx]->key);
        Node* lastNode = nodes[lastIdx];
        nodes.pop_back();

        if (lastIdx > 0) {
            Node* parent = nodes[(lastIdx - 1) / 2];
            if (parent->left == lastNode) {
                parent->left = nullptr;
            } else {
                parent->right = nullptr;
            }
        }

        delete lastNode;
        bubbleDown(0);
        
        return minValue;
    }

    // Просеивание вниз
    void bubbleDown(int idx) {
        int leftIdx = 2 * idx + 1;
        int rightIdx = 2 * idx + 2;

        if (leftIdx >= nodes.size()) return;

        int smallestIdx = leftIdx;
        if (rightIdx < nodes.size() && nodes[rightIdx]->key < nodes[leftIdx]->key) {
            smallestIdx = rightIdx;
        }

        if (nodes[idx]->key > nodes[smallestIdx]->key) {
            swap(nodes[idx]->key, nodes[smallestIdx]->key);
            bubbleDown(smallestIdx);
        }
    }
};

// Функция для получения минимальной суммы
long long getMinimumCost(vector<long long>& lengths) {  
    Heap minHeap;

    for (int i = 0; i < lengths.size(); i++) {
        minHeap.insert(lengths[i]);
    }

    long long cost = 0;
    // Пока в куче есть более одного элемента
    while (minHeap.nodes.size() > 1) {
        long long a = minHeap.pop();  
        long long b = minHeap.pop();  

        cost += a + b;
        minHeap.insert(a + b);
    }
    return cost;
}

int main() {
    int n;
    cin >> n;

    vector<long long> lengths(n);  

    // Ввод длин из консоли
    for (int i = 0; i < n; i++) {
        cin >> lengths[i];
    }

    // Вывод результата
    cout << getMinimumCost(lengths) << endl;

    return 0;
}