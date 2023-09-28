#include <iostream>
using namespace std;
struct Node(){
    int data;
    Node* nxtNode;
}
class LinkedList{
    private:
        Node* head;
    public:
        LinkedList() : head(nullptr){}
        void push_fron(int value){
            Node* newNode = new Node(value)
        }
}
int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }
    for(int i = 0;i<n;i++){
        if ((i) % 2 == 0){
            cout<<arr[i]<<" ";
        }
    }
    return 0;
}
