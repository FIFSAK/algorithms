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
    return j;

}

int main() {
	string city; cin>>city;
    int n; cin>>n;
    vector<string> v(n);
    for(int i = 0; i < n; i++){
        cin>>v[i];
    }
    int max = -1;
    vector<string> max_s;
    for(auto cur: v){
        int temp = kmp(city, cur);
        if (temp>max){
            max_s.clear();
            max = temp;
            max_s.push_back(cur);
        }
        else if(temp == max){
            max_s.push_back(cur);
        }
    }
    cout<<max_s.size()<<endl;
    for(auto cur: max_s){
        cout<<cur<<endl;
    }
    


}