#include <iostream>
#include <vector>
#include <string>
#include <iomanip> 
#include <algorithm>
#include <map>

using namespace std;



int main() {
    int n; cin>>n;
    map<string, string> mp;
    vector<string> v;
    for(int i = 0; i < n; i++){
        string orig, nw; cin>>orig>>nw;
        auto it = find(v.begin(), v.end(), orig);
        if(it != v.end() && distance(v.begin(), it)%2==1){
            int ind = distance(v.begin(), it);
            v[ind] = nw;
        }
        else{
            v.push_back(orig);
            v.push_back(nw);
        }

    }
    // cout<<"-----------------------"<<endl;
    for(int i = 0;i<v.size()-1;i+=2){
        mp[v[i]] = v[i+1];
    }
    cout<<mp.size()<<endl;
    for(auto cur: mp){
        cout<<cur.first<<" "<<cur.second<<endl;
    }
    return 0;
}