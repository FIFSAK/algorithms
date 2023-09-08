#include <iostream>
using namespace std;
string fu(string s){
    string result;
    int skip = 0;
    result = "";
    for(int i = s.length()-1; i>-1;i--){
        if(s[i] == '#'){
            skip++;
        } 
        else if(skip == 0){
            result += s[i];
        }
        else{
            skip--;
        }
    }
    return result;
}
int main(){
    string s, s2;
    cin>>s>>s2;
    if (fu(s)==fu(s2)){
         cout<<"Yes";
         return 0;
    }
    cout<<"No";


   
}