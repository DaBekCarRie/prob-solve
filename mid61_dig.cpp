#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int r, c;
int a, b, x, y;
char area[55][55];
int dis[55][55];
int result = INF;

// A helper function to perform DFS
void dfs(int i, int j, int nub) {
    dis[i][j] = nub;

    if (i == x-1 && j == y-1) {
        result = min(result, nub);
        return;
    }

    int cost = 1;
    if (area[i][j] == '|') cost = 2;
    if (area[i][j] == '-') cost = 2;

    int moves[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};

    for (int k=0; k<4; k++) {
        int ni = i + moves[k][0];
        int nj = j + moves[k][1];

        if (ni >= 0 && ni < r && nj >= 0 && nj < c && area[ni][nj] != '#') {
            int new_cost = cost;
            if (area[ni][nj] == '|') new_cost++;
            if (area[ni][nj] == '-') new_cost++;

            if (nub+new_cost < dis[ni][nj]) {
                dfs(ni, nj, nub+new_cost);
            }
        }
    }
}

int main() {
    cin >> r >> c >> a >> b >> x >> y;

    for (int i=0; i<r; i++) {
        for (int j=0; j<c; j++) {
            cin >> area[i][j];
            dis[i][j] = INF;
        }
    }

    dfs(a-1, b-1, 0);

    if (result == INF) {
        cout << -1 << endl;
    } else {
        cout << result << endl;
    }

    return 0;
}