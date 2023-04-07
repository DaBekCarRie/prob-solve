#include <iostream>
#include <vector>
#include <string>
using namespace std;

int lcs(string s, string t, int i, int j, vector<vector<int>>& memo) {
    if (i < 0 || j < 0) {
        return 0;
    }
    if (memo[i][j] != -1) {
        return memo[i][j];
    }
    int ans = 0;
    if (s[i] == t[j]) {
        ans = lcs(s, t, i-1, j-1, memo) + 1;
    } else {
        ans = max(lcs(s, t, i-1, j, memo), lcs(s, t, i, j-1, memo));
    }
    memo[i][j] = ans;
    return ans;
}

int main() {
    string s, t;
    cin >> s >> t;
    int n = s.length(), m = t.length();
    vector<vector<int>> memo(n+1, vector<int>(m+1, -1));
    int len = lcs(s, t, n-1, m-1, memo);
    cout << len << endl;
    string ans = "";
    int i = n-1, j = m-1;
    while (i >= 0 && j >= 0) {
        if (s[i] == t[j]) {
            ans = s[i] + ans;
            i--;
            j--;
        } else if (memo[i-1][j] > memo[i][j-1]) {
            i--;
        } else {
            j--;
        }
    }
    cout << ans << endl;
    return 0;
}