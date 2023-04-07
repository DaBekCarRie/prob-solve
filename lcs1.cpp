#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int lcs(string s, string t, int i, int j, unordered_map<string, int>& memo) {
    if (i == 0 || j == 0) {
        return 0;
    }
    string key = to_string(i) + "," + to_string(j);
    if (memo.count(key)) {
        return memo[key];
    }
    if (s[i-1] == t[j-1]) {
        memo[key] = 1 + lcs(s, t, i-1, j-1, memo);
    } else {
        memo[key] = max(lcs(s, t, i-1, j, memo), lcs(s, t, i, j-1, memo));
    }
    return memo[key];
}

int main() {
    string s, t;
    cin >> s >> t;
    unordered_map<string, int> memo;
    cout << lcs(s, t, s.length(), t.length(), memo) << endl;
    return 0;
}