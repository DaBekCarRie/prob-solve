#include <bits/stdc++.h>
using namespace std;

const int MAXN = 15005;

int N, R;
int minn[MAXN];
pair<int, int> q[MAXN];

vector<int> vec[MAXN];
queue<pair<int, int>> qq;

inline int sq(int x) { return x * x; }

inline int dist(int i, int j) {
    return sq(q[i].first - q[j].first) + sq(q[i].second - q[j].second);
}

void bfs() {
    qq.push({0, 0});
    while (!qq.empty()) {
        int u = qq.front().first, d = qq.front().second;
        qq.pop();
        if (d >= minn[u]) continue;
        minn[u] = d;
        for (auto v : vec[u])
            qq.push({v, d + 1});
    }
}

int main() {
    cin >> N >> R;
    q[0] = {0, 0}, minn[0] = 1e9;
    for (int i = 1; i <= N; i++) {
        cin >> q[i].first >> q[i].second;
        minn[i] = 1e9;
    }
    q[N + 1] = {100, 100}, minn[N + 1] = 1e9;
    for (int i = 0; i <= N; i++)
        for (int j = i + 1; j <= N + 1; j++)
            if (dist(i, j) <= R * R)
                vec[i].push_back(j), vec[j].push_back(i);
    bfs();
    if (minn[N + 1] != 1e9)
        cout << minn[N + 1];
    else
        cout << "-1";
    return 0;
}