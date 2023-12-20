#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;
    vector<vector<int>> field(m, vector<int>(n));
    queue<pair<int, int>> q;
    vector<vector<int>> time(m, vector<int>(n, -1));

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> field[i][j];
            if (field[i][j] == 2) {
                q.push({i, j});
                time[i][j] = 0;
            }
        }
    }

    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < m && ny >= 0 && ny < n && field[nx][ny] == 1) {
                field[nx][ny] = 2;
                q.push({nx, ny});
                time[nx][ny] = time[x][y] + 1;
            }
        }
    }

    int maxTime = 0;
    bool impossible = false;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (field[i][j] == 1) {
                impossible = true;
            }
            maxTime = max(maxTime, time[i][j]);
        }
    }

    if (impossible) cout << -1 << endl;
    else cout << maxTime << endl;

    return 0;
}
