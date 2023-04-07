#include<bits/stdc++.h>
using namespace std;

char demo[130][130];
int keep[130][130][3];
int w, h, u, v, result, result1;
int maxx1 = 0, maxx2 = 0;

int walk(int h1, int w1, int status) {
    if (keep[h1][w1][status] != -1) {
        return keep[h1][w1][status];
    }
    if (w1 == w-1 && demo[h1][w1] == '#' && status == 1) {
        status = 2;
    }
    if (w1 == 0 && demo[h1][w1] == '#' && status == 2) {
        status = 1;
    }
    if (demo[h1][w1] == '$') {
        return 1;
    }
    if (demo[h1][w1] == '@') {
        return 0;
    }
    if (demo[h1][w1] == '.') {
        return keep[h1][w1][status] = walk(h1+1, w1, status);
    }
    if (demo[h1][w1] == '#' && status == 1) {
        return keep[h1][w1][status] = walk(h1, w1+1, status);
    }
    if (demo[h1][w1] == '#' && status == 2) {
        return keep[h1][w1][status] = walk(h1, w1-1, status);
    }
}

int main() {
    cin >> w >> h;
    memset(keep, -1, sizeof(keep));
    for (int i=0; i<h; i++) {
        for (int j=0; j<w; j++) {
            cin >> demo[i][j];   
        }
    }
    for (int j=0; j<w; j++) {
        result += walk(0, j, 1); 
        result += walk(0, j, 2);
    }
    maxx1 = result;
    for (int i=0; i<h; i++) {
        for (int j=0; j<w; j++) {
            if (demo[i][j] == '#') {
                demo[i][j] = '.';
                result1 = 0;
                memset(keep, -1, sizeof(keep));
                for (int k=0; k<w; k++) {
                    result1 += walk(0, k, 1);
                    result1 += walk(0, k, 2);
                }   
                demo[i][j] = '#';
                if (result1 > maxx2) {
                    maxx2 = result1;
                }
            }
        }
    }
    cout << maxx1 << ' ' << maxx2;
}