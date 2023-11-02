#include <iostream>
#include <cassert>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
using namespace std;

void prefix(vector<int> &v, int i, int j, string s){
    while (i<v.size()){
        if (s[j] == s[i]){
            v[i] = j+1;
            j++;
            i++;
        }
        else{
            if (j==0){
                v[i]=0;
                i+=1;
            }
            else{
                j = v[j-1];
            }
        }
    }
}

bool kmp(vector<int> v, string s, string sub){
    int i = 0;
    int j = 0;
    while(i<s.size()){
        if (s[i]==sub[j]){
            i++;
            j++;
            if(j == sub.size()){
                break;
            }
        }
        else{
            if (j>0){
                j = v[j-1];
            }
            else{
                i+=1;
            }
        }
    }
    return j==sub.size();

}

int main() {
	string s; cin>>s;
    string temp = s;
    string sub; cin>>sub;
    int cnt = 1;
    while(s.size()<sub.size()){
        s+=temp;
        cnt++;
    }
    vector<int> v(sub.size());
    prefix(v, 1, 0, sub);
    
    if(kmp(v, s, sub)){
        cout<<cnt;
    }
    else{
        s+=temp;
        cnt++;
        if(kmp(v, s, sub)){
            cout<<cnt;
        }
        else{
            cout<<-1;
        }
    }
}