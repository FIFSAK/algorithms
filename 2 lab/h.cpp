#include <iostream>
 
using namespace std;
 
struct Node{
    int val;
    Node* next;
    Node(): val(0), next(nullptr) {}
    Node(int x): val(x), next(nullptr) {}
    Node(Node* next): val(0), next(next) {}
    Node(int x, Node* next): val(x), next(next) {}
};
 
Node* insert(Node* head, Node* node, int p){
    /* write your code here */
    if (p == 0) {
        node->next = head;
        return node;
    }

    Node* cur = head;
    for (int i = 0; i < p-1 ; i++) {
        cur = cur->next;
    }

    // if (cur == nullptr) {
    //     // Позиция вне допустимого диапазона
    //     return head;
    // }

    node->next = cur->next;
    cur->next = node;

    return head;
}
 
Node* remove(Node* head, int p){
    /* write your code here */
    if (p == 0) {
        // Removing the head of the list
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    Node* cur =  head;
    for(int i = 0;i<p-1; i++){
        cur = cur->next;
    }
    Node* temp = cur->next;
    cur->next = cur->next->next;
    delete temp;

    return head;
}
Node* replace(Node* head, int p1, int p2){
    /* write your code here */
    Node* prev1 = nullptr;
    Node* cur1 = head;
    for(int i = 0;i < p1; i++){
        prev1 = cur1;
        cur1 = cur1->next;
    }
    if (prev1) {
        prev1->next = cur1->next;
    } else {
        head = cur1->next;
    }
    // Node* prev2 = nullptr;
    // Node* cur2 = cur1;
    // for(int i = 0; i<p2;i++){
    //     cur2 = cur2->next;
    // }
    Node* prev2 = nullptr;
    Node* cur2 = head;
    for (int i = 0; i < p2; i++) {
        prev2 = cur2;
        cur2 = cur2->next;
    }
    if (prev2) {
        prev2->next = cur1;
    } else {
        head = cur1;
    }
    cur1->next = cur2;

    return head;
}
Node* reverse(Node* head){
    /* write your code here */
    Node* current = head;
    Node *prev = NULL, *next = NULL;
    while (current != NULL) {
        // Store next
        next = current->next;
        // Reverse current node's pointer
        current->next = prev;
        // Move pointers one position ahead.
        prev = current;
        current = next;
    }
    head = prev;
    return head;

}
 
void print(Node* head){
    /* write your code here */
    Node* current = head;
    if(!current){
        cout<<-1;
        return;
    }
    while (current) {
        cout << current->val << " ";
        current = current->next;
    }
    cout<<endl;
}
 
Node* cyclic_left(Node* head, int x){
    /* write your code here */
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
 
Node* cyclic_right(Node* head, int x){
    /* write your code here */
    if (x == 0 || !head || !head->next) {
        return head;
    }

    // Find the length of the linked list
    int length = 1;
    Node* cur = head;
    while (cur->next) {
        length++;
        cur = cur->next;
    }

    // If x is equal to the length, then the list remains unchanged
    if (x == length) {
        return head;
    }

    // Calculate the position to break the list
    int breakPos = length - x;

    // Traverse to the break position
    cur = head;
    for (int i = 1; i < breakPos; i++) {
        cur = cur->next;
    }

    // Break the list and attach the broken part to the front
    Node* newHead = cur->next;
    cur->next = nullptr;
    Node* temp = newHead;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = head;

    return newHead;
}
 
int main(){
    Node* head = nullptr;
    while (true)
    {
        int command; cin >> command;
        if (command == 0){
            // cout<<"you out"<<endl;
            break;
        }
        else if(command == 1){
            // cout<<"you insert"<<endl;
            int x, p; cin >> x >> p;
            head = insert(head, new Node(x), p);
        }
        else if (command == 2){
            // cout<<"you remove"<<endl;
            int p; cin >> p;
            head = remove(head, p);
        }
        else if (command == 3){
            // cout<<"you print"<<endl;
            print(head);
        }
        else if (command == 4){
            // cout<<"you replace"<< endl;
            int p1, p2; cin >> p1 >> p2;
            head = replace(head, p1, p2);
        }
        else if (command == 5){
            // cout<<"you reverse"<< endl;
            head = reverse(head);
        }
        else if (command == 6){
            // cout<<"you left"<< endl;
            int x; cin >> x;
            head = cyclic_left(head, x);
        }
        else if (command == 7){
            // cout<<"you right"<< endl;
            int x; cin >> x;
            head = cyclic_right(head, x);
        }   
    }
    return 0;
}