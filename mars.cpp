#include <iostream>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

const int MAX_N = 1000;
const int MAX_M = 26;

int save[MAX_N][MAX_M][MAX_M];

int choose(int now, int next){
    int turn1 = abs(next-now);
    int turn2 = 26-abs(next-now);
    return min(turn1,turn2);
}

int solve(const string& p) {
    int size_p = p.length();
    int min_result = INT_MAX;

    for (int i = 0; i < size_p; i++) {
        for (int j = 0; j < MAX_M; j++) {
            for (int k = 0; k < MAX_M; k++) {
                save[i][j][k] = INT_MAX;
            }
        }
    }

    // Set initial values
    save[0][p[0]-'A']['A'-'A'] = choose(0, p[0]-'A');
    save[0]['A'-'A'][p[0]-'A'] = choose(0, p[0]-'A');

    // If string has only one element, return the result
    if (size_p == 1) {
        return save[0]['A'-'A'][p[0]-'A'];
    }

    // Solve the problem
    for (int i = 1; i < size_p; i++) {
        for (int j = 0; j < MAX_M; j++) {
            for (int k = 0; k < MAX_M; k++) {
                if (save[i-1][j][k] != INT_MAX) {
                    save[i][p[i]-'A'][k] = min(save[i][p[i]-'A'][k], save[i-1][j][k] + choose(j, p[i]-'A')); 
                    save[i][j][p[i]-'A'] = min(save[i][j][p[i]-'A'], save[i-1][j][k] + choose(k, p[i]-'A'));    
                }

                if (i == size_p-1) {
                    min_result = min(min_result, save[i][j][p[i] - 'A']);
                    min_result = min(min_result, save[i][p[i] - 'A'][k]);
                }
            }
        }
    }

    return min_result;
}

int main() {
    int test;
    cin >> test;

    while (test--) {
        string p;
        cin >> p;
        cout << solve(p) << endl;
    }

    return 0;
}