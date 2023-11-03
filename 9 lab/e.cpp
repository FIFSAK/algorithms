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

int kmp(string s, string sub){
    int i = 0;
    int j = 0;
    int cnt = 0;
    vector<int> v(sub.size());
    prefix(v, 1, 0, sub);
    while(i<s.size()){
        if (s[i]==sub[j]){
            i++;
            j++;
            if(j == sub.size()){
                cnt++;
                j = 0;
                i = cnt;
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
    return cnt;

}

int main() {
    int size; cin>>size;
    for(int i = 0;i<size;i++){
        string s; cin>>s;
        int n; cin>>n;
        string sub = s;
        int cnt = kmp(s,sub);
        while (cnt<n){
            s += sub;
            cnt = kmp(s, sub);
        }
        cout<<s.size()<<endl;
    }
	

}