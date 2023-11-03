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

vector<int> kmp(vector<int> v, string s, string sub){
    int i = 0;
    int j = 0;
    vector<int> ans;
    while(i<s.size()){
        if (s[i]==sub[j]){
            i++;
            j++;
            if(j == sub.size()){
                ans.push_back(i-j+1);
                j = 0;
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
    return ans;

}

int main() {
    string pass; cin>>pass;
    vector<int> v(pass.size());
    prefix(v, 1, 0, pass);
    cout<<pass.size() - v[pass.size() - 1];;


}