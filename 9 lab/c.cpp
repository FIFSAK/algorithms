#include <iostream>
#include <cassert>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
using namespace std;

int main() {
	string orig; cin>>orig;
    string s; cin>>s;
    int cnt = 0;
    int m = orig.size()-1;
    for(int i = 0;i<orig.size();i++){
        char temp = orig[m];
        orig.erase(m,1);
        orig = temp+orig;
        cnt++;
        if(orig == s){
            cout<<cnt;
            return 0;
        }
    }
    cout<<-1;

}