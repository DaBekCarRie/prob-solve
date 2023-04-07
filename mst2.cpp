#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, w;
};

struct UnionFind {
    vector<int> parent;
    vector<int> size;
    void make_set(int v) {
        parent[v] = v;
        size[v] = 1;
    }
    int find_set(int v) {
        if (v == parent[v]) {
            return v;
        }
        return parent[v] = find_set(parent[v]);
    }
    void union_sets(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (a != b) {
            if (size[a] < size[b]) {
                swap(a, b);
            }
            parent[b] = a;
            size[a] += size[b];
        }
    }
};

int kruskal(int n, vector<Edge>& edges) {
    sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) {
        return a.w < b.w;
    });

    UnionFind uf;
    uf.parent.resize(n + 1);
    uf.size.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        uf.make_set(i);
    }

    int mst_cost = 0;
    for (const auto& e : edges) {
        if (uf.find_set(e.u) != uf.find_set(e.v)) {
            uf.union_sets(e.u, e.v);
            mst_cost += e.w;
        }
    }

    return mst_cost;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<Edge> edges(m);
    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    int mst_cost = kruskal(n, edges);

    cout << mst_cost << endl;

    return 0;
}