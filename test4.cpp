#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> topologicalSort(const vector<vector<int>>& adjMatrix) {
    int vertices = adjMatrix.size();
    vector<int> inDegree(vertices, 0);
    stack<int> s;

    // Calculate in-degrees
    for (int u = 0; u < vertices; ++u) {
        for (int v = 0; v < vertices; ++v) {
            if (adjMatrix[u][v] != 0) {
                inDegree[v]++;
            }
        }
    }

    // Push vertices with in-degree 0 onto the stack
    for (int u = 0; u < vertices; ++u) {
        if (inDegree[u] == 0) {
            s.push(u);
        }
    }

    vector<int> result;

    // Topological sorting
    while (!s.empty()) {
        int u = s.top();
        s.pop();
        result.push_back(u);

        for (int v = 0; v < vertices; ++v) {
            if (adjMatrix[u][v] != 0) {
                if (--inDegree[v] == 0) {
                    s.push(v);
                }
            }
        }
    }

    return result;
}

int main() {
    // Example graph represented by an adjacency matrix
    vector<vector<int>> adjMatrix = {
        {0, 0, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 1},
        {0, 1, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0}
    };

    vector<int> sortedVertices = topologicalSort(adjMatrix);

    cout << "Topological Order: ";
    for (int vertex : sortedVertices) {
        cout << vertex << " ";
    }
    cout << endl;

    return 0;
}
