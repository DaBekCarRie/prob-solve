#include <iostream>
#include <algorithm>
#include <cstring>
#define MAXLEN 500
#define INF 1e9

char x[MAXLEN+5], y[MAXLEN+5];
int dp[2][MAXLEN+5];

int main() {
    std::cin >> x;
    std::cin >> y;

    int n = strlen(x), m = strlen(y);
    std::fill(dp[0], dp[0] + m + 1, INF);
    std::fill(dp[1], dp[1] + m + 1, INF);
    dp[0][0] = 0;

    for (int i = 1; i <= n; i++) {
        dp[i&1][0] = i;
        for (int j = 1; j <= m; j++) {
            if (x[i-1] == y[j-1]) {
                dp[i&1][j] = dp[(i-1)&1][j-1];
            } else {
                dp[i&1][j] = std::min({ dp[i&1][j-1], dp[(i-1)&1][j], dp[(i-1)&1][j-1] }) + 1;
            }
        }
    }
    std::cout << dp[n&1][m] << std::endl;
}