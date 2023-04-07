#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

const int MAXN = 1120, MAXK = 14;

int n, k;
bool is_prime[MAXN+1];
vector<int> primes;
int dp[MAXN+1][MAXK+1];

void sieve() {
    memset(is_prime, true, sizeof(is_prime));
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= MAXN; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (int j = i*i; j <= MAXN; j += i) {
                is_prime[j] = false;
            }
        }
    }
}

int main() {
    sieve();
    dp[0][0] = 1;
    for (int p : primes) {
        for (int i = MAXN; i >= p; i--) {
            for (int j = 1; j <= MAXK; j++) {
                dp[i][j] += dp[i-p][j-1];
            }
        }
    }
    while (cin >> n >> k && !(n == 0 && k == 0)) {
        cout << dp[n][k] << endl;
    }
    return 0;
}