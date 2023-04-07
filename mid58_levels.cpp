#include <iostream>
#include <algorithm>

using std::cin;
using std::cout;
using std::min;

const int MAX_N = 200;

int main() {
    int n, m;
    int exam1[MAX_N], exam2[MAX_N], exam3[MAX_N];
    cin >> n >> m;
    for (int i = 1; i < n; i++) {
        cin >> exam1[i] >> exam2[i] >> exam3[i];
    }
    int status1 = 0, status2 = 0, status3 = 0, now_level = 1;
    for (int i = 0; i < m; i++) {
        int ex1, ex2, ex3;
        cin >> ex1 >> ex2 >> ex3;
        if (ex1 >= exam1[now_level] && !status1) {
            status1 = 1;
        }
        if (ex2 >= exam2[now_level] && !status2) {
            status2 = 1;
        }
        if (ex3 >= exam3[now_level] && !status3) {
            status3 = 1;
        }
        if (status1 && status2 && status3) {
            now_level++;
            status1 = 0;
            status2 = 0;
            status3 = 0;
        }
    }
    now_level = min(n, now_level);
    cout << now_level << '\n';
    return 0;
}