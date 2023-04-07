#include<bits/stdc++.h>
using namespace std;

const int MAXN = 250000;
vector<int> vec[MAXN];
queue<int> q;
int visit[MAXN], dis[MAXN];
int N, M, S, T;

void bfs() {
    while (!q.empty()) {
        int now = q.front(); q.pop();
        for (int i = 0; i < vec[now].size(); i++) {
            int willgo = vec[now][i];
            if (visit[willgo] == 1) continue;
            visit[willgo] = 1;
            dis[willgo] = dis[now] + 1;
            q.push(willgo);
        }       
    }
}

int main() {
    cin >> N >> M >> S >> T;

    for (int i = 0, x, y; i < M; i++) {
        cin >> x >> y;
        vec[x].push_back(y);
        vec[y].push_back(x);
    }

    for (int i = 0, aaa; i < S; i++) {
        cin >> aaa;
        q.push(aaa);
        visit[aaa] = 1;
    }

    bfs();

    for (int i = 0, aaa; i < T; i++) {
        cin >> aaa;
        cout << dis[aaa] << "\n";
    }
}