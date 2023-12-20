#include <iostream>
#include <vector>
#include <queue>
using namespace std;




int main() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int>> field(n+1, vector<int>(n+1));
    vector<int> isblack(n+1, 0);


    for (int i = 0; i < m; ++i) {
        int a, b; cin>>a>>b;
        field[a][b]=1;
        field[b][a]=1;
    }
    while(q--){
        int a, b; cin>>a>>b;
        if(a == 1){
            isblack[b]=1;
        }
        else if (a == 2) {
            if (isblack[b] == 1) {
                cout << 0 << endl; 
            } else {
                vector<int> distance(n + 1, -1);
                queue<int> que;
                vector<bool> visited(n + 1, false);
                que.push(b);
                visited[b] = true;
                distance[b] = 0;
                int minDistanceToBlack = -1; 

                while (!que.empty()) {
                    int current = que.front();
                    que.pop();

                    if (isblack[current] == 1) { 
                        minDistanceToBlack = distance[current];
                        break; 
                    }

                    for (int i = 1; i <= n; ++i) {
                        if (!visited[i] && field[current][i] == 1) {
                            que.push(i);
                            visited[i] = true;
                            distance[i] = distance[current] + 1;
                        }
                    }
                }
                cout << minDistanceToBlack << endl;
            }
        }
    }
    return 0;
}
