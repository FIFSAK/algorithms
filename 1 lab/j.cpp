#include <iostream>
#include <deque>

using namespace std;

int main(){
    char method;
    deque<int> deq;
    while(method!='!'){
        int num;
        cin>>method;
        if(method == '+'){
            cin>>num;
            deq.push_front(num);
        }
        if(method == '-'){
            cin>>num;
            deq.push_back(num);
        }
        if(method == '*'){
            if(deq.size() == 1){
                cout << deq.back() * 2 << endl;
                deq.pop_back(); 
            }
            else if (deq.empty()){
                cout<<"error"<<endl;
            }
            else{
                int sum = deq.back() + deq.front(); 
                deq.pop_back(); 
                deq.pop_front();
                cout << sum << endl;
            }
        }
    }
}