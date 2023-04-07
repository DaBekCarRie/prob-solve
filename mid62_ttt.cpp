#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100010;
vector<int> adj[MAXN];
int color[MAXN];
pair<int, int> edges[MAXN];

bool is_bipartite(int u, int v) {
    queue<int> q;
    q.push(1);
    color[1] = 1;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int y : adj[x]) {
            if ((x == u && y == v) || (x == v && y == u)) {
                continue;
            }
            if (color[y] == 0) {
                color[y] = 3 - color[x];
                q.push(y);
            } else if (color[y] == color[x]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        edges[i] = {u, v};
    }
    for (int i = 1; i <= m; i++) {
        if (is_bipartite(edges[i].first, edges[i].second)) {
            cout << edges[i].first << ' ' << edges[i].second << '\n';
            break;
        }
        for (int j = 1; j <= n; j++) {
            color[j] = 0;
        }
    }
    return 0;
}