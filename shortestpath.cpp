#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> g[111111];
int n, m, dis[111111], cnt[111111];

void shortestpath_faster_algorithm() {
    for (int i = 1; i <= n; i++) {
        dis[i] = 1e9;
    }
    dis[1] = 0;
    queue<int> q;
    q.push(1);
    cnt[1] = 1;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        cnt[u] = 0;
        for (auto it : g[u]) {
            int v = it.first, w = it.second;
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                if (!cnt[v]) {
                    q.push(v);
                    cnt[v] = 1;
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].emplace_back(make_pair(v, w));
        g[v].emplace_back(make_pair(u, w));
    }
    shortestpath_faster_algorithm();
    cout << dis[n];
    return 0;
}