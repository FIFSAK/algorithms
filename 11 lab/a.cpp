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
    int n, m;
    cin >> n >> m;
    vector<pair<int, pair<int, int>>> edges;

    // Считывание сегментов и создание рёбер между всеми парами вершин внутри каждого сегмента
    for (int i = 0; i < m; i++) {
        int l, r, c;
        cin >> l >> r >> c;
        --l; // уменьшаем l и r на 1, чтобы индексация начиналась с нуля
        --r;
        for (int a = l; a < r; ++a) {
            for (int b = a + 1; b <= r; ++b) {
                edges.push_back({c, {a, b}});
            }
        }
    }

    // Сортировка рёбер по весу
    sort(edges.begin(), edges.end());

    // Инициализация родителей для DSU
    parent.resize(n);
    for (int i = 0; i < n; i++)
        parent[i] = i;

    long long total_weight = 0;
    for (auto edge : edges) {
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
