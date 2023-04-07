#include <iostream>
#include <set>
#include <map>
#include <climits>

using namespace std;

set<int> unvisited;
map<int, int> dist;
map<int, int> price;
map<int, map<int, int>> graph;

void dijkstra(int start) {
    for (auto p : price) {
        dist[p.first] = INT_MAX;
        unvisited.insert(p.first);
    }
    dist[start] = 0;

    while (!unvisited.empty()) {
        int u = *unvisited.begin();
        for (auto v : unvisited) {
            if (dist[v] < dist[u]) {
                u = v;
            }
        }

        unvisited.erase(u);

        for (auto p : graph[u]) {
            int v = p.first;
            int w = p.second;
            int alt = dist[u] + w;
            if (alt < dist[v]) {
                dist[v] = alt;
            }
        }
    }
}

int main() {
    int m, n, l;
    cin >> n >> m >> l;
    for (int i = 1; i <= n; i++) {
        cin >> price[i];
    }
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u][v] = w;
        graph[v][u] = w;
    }

    dijkstra(1);

    int summ = 0;
    for (int i = 2; i <= n; i++) {
        summ += min(dist[i] * l, dist[i] * price[i]);
    }
    cout << summ << endl;

    return 0;
}