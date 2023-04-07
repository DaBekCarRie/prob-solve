#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 60;
int wood[MAX_N];
int dp[MAX_N][MAX_N];

int get_minimum_cutting(int start, int end){
    if (end - start == 1){
        return 0;
    }
    if (dp[start][end] != -1){
        return dp[start][end];
    }
    int result = INT_MAX;
    for (int middle = start + 1; middle < end; middle++){
        result = min(result, get_minimum_cutting(start, middle) + get_minimum_cutting(middle, end) + (wood[end] - wood[start])); 
    }
    dp[start][end] = result;
    return dp[start][end];
}

int main(){
    while(true){
        int length, n_cuts;
        cin >> length;
        if (length == 0){
            break;
        }
        cin >> n_cuts;
        memset(dp, -1, sizeof(dp));
        wood[0] = 0;
        for (int i = 1; i <= n_cuts; i++){
            cin >> wood[i];    
        }
        wood[n_cuts + 1] = length;
        printf("The minimum cutting is %d.\n", get_minimum_cutting(0, n_cuts + 1));
        for (int i = 1; i <= n_cuts; i++){
            wood[i] = 0;    
        }
    }
    return 0;
}

/* Example input:
100
3
25 50 75
10
4
4 5 7 8
0
*/