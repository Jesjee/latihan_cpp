#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Struktur edge
struct Edge {
    int u, v, weight;
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

// Union-Find (DSU)
vector<int> parent;

int findSet(int x) {
    if (parent[x] != x)
        parent[x] = findSet(parent[x]);
    return parent[x];
}

void unionSet(int a, int b) {
    parent[findSet(a)] = findSet(b);
}

int main() {
    int V, E;
    cout << "Masukkan jumlah vertex dan edge: ";
    cin >> V >> E;

    vector<Edge> edges;
    cout << "Masukkan edge (u v bobot):\n";
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }

    sort(edges.begin(), edges.end());
    parent.resize(V);
    for (int i = 0; i < V; i++) parent[i] = i;

    int totalWeight = 0;
    vector<Edge> mstEdges;

    for (const Edge& e : edges) {
        if (findSet(e.u) != findSet(e.v)) {
            unionSet(e.u, e.v);
            mstEdges.push_back(e);
            totalWeight += e.weight;
        }
    }

    // Output sesuai contoh
    cout << "\nEdges dalam Minimum Spanning Tree:\n";
    for (const Edge& e : mstEdges) {
        cout << e.u << " - " << e.v << " (Bobot: " << e.weight << ")\n";
    }
    cout << "Total Bobot MST: " << totalWeight << endl;

    return 0;
}