#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_K = 1000;
const int MAX_N = 100000;

int keep[MAX_K][3]; // c, p, w values for each item in keep array
int material[MAX_N]; // array of material values
int n, k;

int main() {
    int matermax = -1e9;
    int result = 1e9;

    cin >> k >> n;

    for (int i = 0; i < k; i++) {
        cin >> keep[i][0] >> keep[i][1] >> keep[i][2];
    }

    for (int i = 0; i < n; i++) {
        int mater;
        cin >> mater;
        material[i] = mater;
        if (mater > matermax) {
            matermax = mater;
        }
    }

    for (int i = 0; i < k; i++) {
        int quantity = 0, time = 0;
        if (keep[i][2] < matermax) {
            continue;
        }
        for (int j = 0; j < n; j++) {
            if (quantity + material[j] > keep[i][2]) {
                quantity = 0;
                time++;
            }
            quantity += material[j];
        }
        if (quantity != 0) {
            time++;
        }
        if (keep[i][0] + time * keep[i][1] < result) {
            result = keep[i][0] + time * keep[i][1];
        }
    }

    printf("%d\n", result);

    return 0;
}