#include <iostream>
#include <algorithm>
#include <cmath>
#include <utility>
#include <cstdio>

using namespace std;

pair<double,double> keep[1200];
int casee = 0;
int land, dis;

int main() {
    while(1) {
        int status1 = 1;
        cin >> land >> dis;
        if (land == 0 && dis == 0) {
            break;
        }
        for (int i = 0; i < land; i++) {
            double u, v, l, r;
            cin >> u >> v;
            if (v > dis) {
                status1 = 2;
            }
            l = u - sqrt((dis * dis) - (v * v));
            r = u + sqrt((dis * dis) - (v * v));
            keep[i].first = l;
            keep[i].second = r;
        }
        sort(keep, keep + land);
        if (status1 == 2) {
            casee++;
            printf("Case %d: %d\n", casee, -1);
            continue;
        }
        double now = keep[0].second;
        int result1 = 1;
        for (int i = 1; i < land; i++) {
            if (keep[i].first > now) {
                result1++;
                now = keep[i].second;
            }
            else if (keep[i].first <= now) {
                if (now > keep[i].second) {
                    now = keep[i].second;
                }
                continue;
            }
        }
        if (status1 == 1) {
            casee++;
            printf("Case %d: %d\n", casee, result1);
        }
    }
    return 0;
}