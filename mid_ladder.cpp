#include <iostream>

using namespace std;

const int MAX_N = 1000;

int map[MAX_N + 1];
int save[MAX_N + 1];

int main() {
    int n, m;
    cin >> n >> m;

    map[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> map[i];
    }

    for (int i = 1; i <= m; i++) {
        cin >> save[i];
    }

    int pos = 1;
    for (int i = 1; i <= m; i++) {
        pos += save[i];

        if (pos >= n) {
            pos = n;
            break;
        }
        if (pos <= 0) {
            pos = 1;
            continue;
        }

        pos += map[pos];
        if (pos <= 0) {
            pos = 1;
        } else if (pos >= n) {
            pos = n;
            break;
        }
    }

    cout << pos;
    return 0;
}