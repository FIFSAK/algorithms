#include <iostream>
#include <vector>

using namespace std;

void card(int n){
    vector<int> vec;
    int z = 1;
    int cnt = n;
    int temp;  
    for(int i = n; i > 0; i--){
        vec.push_back(i);
        if(vec.size() > 1){
            while(z < cnt){
                temp = vec.front(); 
                vec.erase(vec.begin());
                vec.push_back(temp);
                z += 1;
            }
            z = 1;
            cnt -= 1;
        }
    }

    for(auto it = vec.rbegin(); it != vec.rend(); ++it) {
        cout << *it << " ";
    }
}
    
int main() {
    int size;
    int n;
    cin>>size;
    for(int i = 0;i<size;i++){
        cin>>n;
        card(n);
        cout<<endl;
    }
}
