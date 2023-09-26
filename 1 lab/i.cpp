#include <iostream>
#include <queue>
using namespace std;
int main(){
    int n, ck=0, cs=0;
    cin>>n;
    queue<char> q;
    for(int i=0; i<n; i++){
        char a;
        cin>>a;
        if(a=='K'){
            ck++;
        }
        if(a=='S'){
            cs++;
        }
        q.push(a);
    }
    int k=0, s=0;
    while((ck!=0)&&(cs!=0)){
        char c=q.front();
        q.pop();
        if(c=='K'&&s==0){
            k++;
            q.push(c);
        }
        if(c=='K'&&s!=0){
            s--;
            ck--;
        }
        if(c=='S'&&k==0){
            s++;
            q.push(c);
        }
        if(c=='S'&&k!=0){
            k--;
            cs--;
        }
    }
    if(cs==0){
        cout<<"KATSURAGI";
    }
    if(ck==0){
        cout<<"SAKAYANAGI";
    }
    return 0;
}