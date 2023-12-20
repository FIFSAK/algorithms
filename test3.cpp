#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Структура для представления ребра графа
struct Edge {
    int u, v, weight;
};

// Сравнение для сортировки рёбер по весу
bool compareEdges(const Edge& a, const Edge& b) {
    return a.weight < b.weight;
}

// Находит корень множества (дерева)
int findRoot(vector<int>& parent, int i) {
    while (parent[i] != i) {
        i = parent[i];
    }
    return i;
}

// Объединяет два множества (дерева) в одно
void unionSets(vector<int>& parent, int x, int y) {
    int rootX = findRoot(parent, x);
    int rootY = findRoot(parent, y);
    parent[rootX] = rootY;
}

// Алгоритм Краскала для построения минимального остовного дерева
vector<Edge> kruskalAlgorithm(int vertices, vector<Edge>& edges) {
    // Сортировка рёбер по весу
    sort(edges.begin(), edges.end(), compareEdges);

    // Инициализация родительских множеств для каждой вершины
    vector<int> parent(vertices);
    for (int i = 0; i < vertices; ++i) {
        parent[i] = i;
    }

    vector<Edge> minimumSpanningTree; // Остовное дерево

    // Проходим по всем рёбрам в отсортированном порядке
    for (const Edge& edge : edges) {
        // Проверяем, принадлежат ли вершины ребра разным поддеревьям
        if (findRoot(parent, edge.u) != findRoot(parent, edge.v)) {
            // Добавляем ребро в остовное дерево
            minimumSpanningTree.push_back(edge);
            // Объединяем поддеревья
            unionSets(parent, edge.u, edge.v);
        }
    }

    return minimumSpanningTree;
}

int main() {
    int vertices = 4;
    vector<Edge> edges = {{0, 1, 1}, {0, 2, 3}, {1, 2, 2}, {1, 3, 4}, {2, 3, 5}};

    vector<Edge> minimumSpanningTree = kruskalAlgorithm(vertices, edges);

    // Выводим рёбра минимального остовного дерева
    cout << "Minimum Spanning Tree edges:\n";
    for (const Edge& edge : minimumSpanningTree) {
        cout << edge.u << " - " << edge.v << " : " << edge.weight << "\n";
    }

    return 0;
}
