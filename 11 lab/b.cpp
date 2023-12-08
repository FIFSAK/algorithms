#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> parent;

int find_set(int v) {
    if (v == parent[v]){
        return v;
    }
    parent[v] = find_set(parent[v]);
    return parent[v];
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b)
        parent[b] = a;
}

int main() {
    int n; cin >> n;
    vector <pair <int, pair <int,int> > > g;
    int vertices[n];
    for (int i = 0; i < n; i ++) {
        cin >> vertices[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            g.push_back(make_pair(vertices[i] + vertices[j], make_pair(i, j)));
        }
    }


    sort(g.begin(), g.end());

    // Инициализация родителей для DSU
    parent.resize(n);
    parent.resize(n);
    for (int i = 0; i < n; i++)
        parent[i] = i;
    long long total_weight = 0;
    for (auto edge : g) {
        int weight = edge.first;
        int u = edge.second.first;
        int v = edge.second.second;

        // Проверка, не образует ли ребро цикл
        if (find_set(u) != find_set(v)) {
            total_weight += weight;
            union_sets(u, v);
        }
    }

    cout << total_weight << endl;
    return 0;
}
