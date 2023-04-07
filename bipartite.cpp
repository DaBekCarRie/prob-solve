#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAXN = 100010;

vector<int> graph[MAXN];
int color[MAXN];

bool bfs(int start) {
    queue<int> q;
    q.push(start);
    color[start] = 1;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int neighbor : graph[node]) {
            if (color[neighbor] == 0) {
                color[neighbor] = -color[node];
                q.push(neighbor);
            } else if (color[neighbor] == color[node]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N, M;
        cin >> N >> M;

        for (int i = 1; i <= N; i++) {
            graph[i].clear();
            color[i] = 0;
        }

        for (int i = 0; i < M; i++) {
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        bool isBipartite = true;
        for (int i = 1; i <= N; i++) {
            if (color[i] == 0) {
                isBipartite &= bfs(i);
            }
        }

        if (isBipartite) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    }

    return 0;
}