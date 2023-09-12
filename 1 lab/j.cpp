#include <iostream>
using namespace std;
struct deq{
    int arr[10000];
    int back = 10000/2 - 1, front = 10000/2;
    void push_back(int x){
        back++;
        arr[back]=x;
    }
    void push_front(int x){
        front--;
        arr[front]=x;
    }
    void sum(){
        if (back >= front ) {
            cout << arr[back] + arr[front] << endl;
            back--;
            front++;
        } else {
            cout << "error" << endl;
        }
    }
};

int main(){
    char method;
    deq a;
    while(method!='!'){
        int num;
        cin>>method;
        if(method == '+'){
            cin>>num;
            a.push_front(num);
        }
        if(method == '-'){
            cin>>num;
            a.push_back(num);
        }
        if(method == '*'){
            a.sum();
        }
        
    }
}