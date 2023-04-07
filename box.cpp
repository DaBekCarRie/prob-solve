#include <iostream>
#include <cstring>

using namespace std;

const int MAXN = 50 + 5;
int N, M;
char s[MAXN][MAXN];
int vis[MAXN][MAXN];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
bool found = false;

void dfs(int x, int y) {
    vis[x][y] = 1;
    if (x == N-1) {
        found = true;
        return;
    }
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
        if (s[nx][ny] == '.' && !vis[nx][ny]) {
            dfs(nx, ny);
            if (found) return;
        }
    }
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> s[i];
    }

    memset(vis, 0, sizeof(vis));

    for (int j = 0; j < M; j++) {
        if (s[0][j] == '.') {
            dfs(0, j);
            if (found) break;
        }
    }

    if (found) {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }

    return 0;
}