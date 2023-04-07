#include <iostream>
#include <stack>
using namespace std;

int demo[25][25];
int check[25][25];
int status = 1;
int n,k;

void dfs(int i, int j, int h) {
    stack<pair<int, int>> s;
    s.push(make_pair(i, j));
    while (!s.empty()) {
        pair<int, int> curr = s.top();
        s.pop();
        int x = curr.first, y = curr.second;
        check[x][y] = 1;
        if (x == n - 1 && y == n - 1) {
            status = 2;
            break;
        }
        if (y + 1 < n && demo[x][y + 1] - h <= k && check[x][y + 1] == 0) {
            s.push(make_pair(x, y + 1));
        }
        if (x + 1 < n && demo[x + 1][y] - h <= k && check[x + 1][y] == 0) {
            s.push(make_pair(x + 1, y));
        }
        if (x - 1 >= 0 && demo[x - 1][y] - h <= k && check[x - 1][y] == 0) {
            s.push(make_pair(x - 1, y));
        }
        if (y - 1 >= 0 && demo[x][y - 1] - h <= k && check[x][y - 1] == 0) {
            s.push(make_pair(x, y - 1));
        }
    }
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> demo[i][j];
        }
    }
    int h = demo[0][0];
    dfs(0, 0, h);
    if (status == 1) {
        cout << "no" << '\n';
    } else {
        cout << "yes" << '\n';
    }
    return 0;
}