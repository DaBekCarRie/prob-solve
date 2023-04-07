#include <bits/stdc++.h>
using namespace std;
int main() { while(1) {
    int n; cin >> n; if (n==0) break;
    while(1) {
        stack<int> s; int a[n], check = 0; cin >> a[0];
        if (a[0] == 0) { cout << '\n'; break; }
        for (int i = 1; i < n; ++i) cin >> a[i];
        for (int i = 1; i <= n; ++i) { s.push(i);
            while (!s.empty() && s.top() == a[check]) ++check, s.pop();
        }
        if (s.empty()) cout << "Yes\n"; else cout << "No\n";
    }
}}