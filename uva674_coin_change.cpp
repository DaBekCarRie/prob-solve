#include <iostream>
#include <cstring>
using namespace std;

int coins[] = {1, 5, 10, 25, 50}; // array of coin values
long long dp[5][7490]; // dynamic programming table

int main() {
    int n;

    // initialize table
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < 5; i++) dp[i][0] = 1;

    // compute table values
    for (int i = 0; i < 5; i++) {
        for (int j = 1; j <= 7489; j++) {
            dp[i][j] = (i > 0 ? dp[i-1][j] : 0) + (j >= coins[i] ? dp[i][j-coins[i]] : 0);
        }
    }

    while (cin >> n) {
        cout << dp[4][n] << endl;
    }

    return 0;
}