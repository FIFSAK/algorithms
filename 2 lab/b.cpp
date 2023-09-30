#include <iostream>
#include <string>

using namespace std;

struct Node {
    string val;
    Node* next;
    Node(string x) : val(x), next(nullptr) {}
};

Node* insert(Node* tail, const string& value) {
    Node* newNode = new Node(value);
    if (!tail) {
        return newNode;
    }
    tail->next = newNode;
    return newNode;
}

void print(Node* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

Node* cyclic_left(Node* head, int x){
     if (x == 0 || !head || !head->next) {
        return head;
    }
    Node* cur = head;
    Node* tail = head;
    while (tail->next){
        tail = tail->next;
    }
    for(int i = 0;i<x-1;i++){
        cur = cur->next;
    }
    if (!cur->next) {
        return head;
    }
    tail->next = head;  
    head = cur->next;   
    cur->next = nullptr;
    return head;
}

int main() {
    Node* head = nullptr;
    Node* tail = nullptr;
    int N, K; 
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        string temp;
        cin >> temp;
        if (!head) {
            head = insert(tail, temp);
            tail = head;
        } else {
            tail = insert(tail, temp);
        }
    }
    head = cyclic_left(head, K);
    print(head);
    return 0;
}
