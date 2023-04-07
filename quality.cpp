#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 40;
char demo[MAXN][MAXN];
int keep[MAXN][MAXN];
int count1 = 0, count2 = 0;
int checkpoint = 0;
int n, m;

void walk(int i, int j) {
    keep[i][j] = 1;
    if (checkpoint == 0 && demo[i][j] == '*') {
        checkpoint = 1;
    } else if (checkpoint == 0 && demo[i][j] == '$') {
        checkpoint = 2;
    } else if (checkpoint == 1 && demo[i][j] == '$') {
        checkpoint = 3;
    } else if (checkpoint == 2 && demo[i][j] == '*') {
        checkpoint = 3;
    }

    if (i+1 >= 0 && i+1 < n && demo[i+1][j] != '#' && keep[i+1][j] != 1) {
        walk(i+1, j);
    }
    if (j+1 >= 0 && j+1 < m && demo[i][j+1] != '#' && keep[i][j+1] != 1) {
        walk(i, j+1);
    }
    if (i-1 >= 0 && i-1 < n && demo[i-1][j] != '#' && keep[i-1][j] != 1) {
        walk(i-1, j);
    }
    if (j-1 >= 0 && j-1 < m && demo[i][j-1] != '#' && keep[i][j-1] != 1) {
        walk(i, j-1);
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> demo[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (demo[i][j] != '#') {
                walk(i, j);
                if (checkpoint == 1) {
                    count1++;
                }
                if (checkpoint == 2) {
                    count1++;
                }
                if (checkpoint == 3) {
                    count2++;
                }
                memset(keep, 0, sizeof(keep));
                checkpoint = 0;
            }
        }
    }
    cout << count2 << ' ' << count1 << '\n';
    return 0;
}