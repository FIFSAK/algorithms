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
        void push_front(int value){
            Node* newNode = new Node{value, head};
            head = newNode;
        }void push_back(int value){
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
};
int main() {
    int n;
    cin>>n;
    int temp;
    LinkedList list;
    for(int i = 0; i<n;i++){
        cin>>temp;
        if((i+1)%2==1){
            list.push_back(temp);
        }        
    }
    Node* cur = list.head;
    while(cur){
        cout<<cur->data<<" ";
        cur = cur->next;
    }


    return 0;
}
    // int n;
    // cin>>n;
    // int arr[n];
    // for(int i = 0;i<n;i++){
    //     cin>>arr[i];
    // }
    // for(int i = 0;i<n;i++){
    //     if ((i) % 2 == 0){
    //         cout<<arr[i]<<" ";
    //     }
    // }
