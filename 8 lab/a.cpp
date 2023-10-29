#include <iostream>
#include <cassert>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
using namespace std;

const long long N = (long long)1e5 + 7;
const long long p = 31;
const long long mod = (long long)1e9 + 7;

long long my_hash(string s) {
    long long h = 0;
    for (long long i = 0; i < s.length(); i++) {
        h = (h + (int(s[i]) - 47) * pow(11, i));
    }
    return h % mod;
}
int main() {
	long long n; cin >> n;
	map<string, long long> mp;
	for(long long i = 0;i<n*2;i++){
		string temp; cin>>temp;
		mp[temp] = 1;
	}
	for(auto cur: mp){
		long long h = my_hash(cur.first);
		if(mp[to_string(h)]==1){
			cout<<"Hash of string " << '"' << cur.first << '"' << " is " << h<<endl;   
		}
	}
	return 0;
}

/*

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <string>
using namespace std;

const long long mod = (long long)1e9 + 7;

long long mod_pow(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (1LL * result * base) % mod;
        }
        base = (1LL * base * base) % mod;
        exp /= 2;
    }
    return result;
}

long long my_hash(string s) {
    long long h = 0;
    for (long long i = 0; i < s.length(); i++) {
        h = (h + (int(s[i]) - 47) * mod_pow(11, i, mod)) % mod;
    }
    return h;
}

int main() {
    long long n; cin >> n;
    map<string, int> mp;
    for(long long i = 0; i < n * 2; i++) {
        string temp; cin >> temp;
        mp[temp]++;
    }
    for(auto cur: mp) {
        long long h = my_hash(cur.first);
        if(mp[to_string(h)] > 0) {
            cout << "Hash of string " << '"' << cur.first << '"' << " is " << h << endl;  
            mp[to_string(h)]--; // Decrement the count after using a hash value
        }
    }
    return 0;
}
*/

