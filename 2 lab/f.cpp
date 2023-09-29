#include <iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
};
class LinkedList{
    // private:
    public:
        Node* head;
        LinkedList() : head(nullptr){}

        void push_back(int value){
            Node* newNode = new Node{value};
            if(!head){
                head = newNode;
                return;
            }
            Node* current = head;
            while (current->next){
                current = current->next;

            }
            current->next = newNode;
        }
        // int change_rac(Node* cur, int data, int pos){
        //     pass;
        // }
        void change_pos(int data, Node* cur){  
            if(!cur->next){
                int temp = cur->data;
                cur->data = data;
                push_back(temp);
                return;
            }
            else{
               int temp = cur->data;
               cur->data = data;
               change_pos(temp, cur->next);
            }

        }
};
int main() {
    int n;
    cin>>n;
    int temp;
    LinkedList list;
    for(int i = 0; i<n;i++){
        cin>>temp;
        list.push_back(temp);       
    }
    int data, pos;
    cin>>data;
    cin>>pos;
    int i = 0;
    Node* cur = list.head;
    while(i<pos){
        cur = cur->next;
        i++;
    }
    list.change_pos(data, cur);
    cur = list.head;
    while(cur){
        cout<<cur->data<<" ";
        cur = cur->next;
    }


    return 0;
}