#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> field(n+1, vector<int>(n+1));
    queue<int> q;
    vector<bool> visited(n+1, false);
    vector<int> distance(n+1, -1); // Distance from the start node to each node.

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> field[i][j];
        }
    }

    int start, end;
    cin >> start >> end;

    q.push(start);
    visited[start] = true;
    distance[start] = 0;

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        if (current == end) { // If we've reached the end node, we can exit the loop.
            break;
        }

        for (int i = 1; i <= n; ++i) {
            if (!visited[i] && field[current][i] == 1) {
                q.push(i);
                visited[i] = true;
                distance[i] = distance[current] + 1;
            }
        }
    }

    cout << distance[end] << endl; // Output the distance to the end node.

    return 0;
}
