#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 1005;
const int MAXG = 105;
const int MAXW = 35;

int P[MAXN], W[MAXN], memo[MAXN][MAXW];

int knapsack(int i, int w, int n) {
    if (i == n || w == 0) return 0;
    if (memo[i][w] != -1) return memo[i][w];
    if (W[i] > w) return memo[i][w] = knapsack(i+1, w, n);
    return memo[i][w] = max(knapsack(i+1, w, n), P[i] + knapsack(i+1, w-W[i], n));
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        memset(memo, -1, sizeof(memo));
        int N, G, ans = 0;
        cin >> N;
        for (int i = 0; i < N; i++)
            cin >> P[i] >> W[i];
        cin >> G;
        while (G--) {
            int MW;
            cin >> MW;
            ans += knapsack(0, MW, N);
        }
        cout << ans << "\n";
    }
    return 0;
}