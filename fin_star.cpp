#include<bits/stdc++.h>
using namespace std;

int dp[100100][3];
int main(){
    int n;
    cin >> n;
    cin >> dp[0][1] >> dp[0][2];
    dp[0][0] = 0;
    
    for (int i=1;i<n;i++){
        int cafe, bakery;
        cin >> cafe >> bakery;
        dp[i][0] = max(dp[i-1][1],max(dp[i-1][2],dp[i-1][0]));     // not choose 
        dp[i][1] = max(dp[i-1][0],dp[i-1][2]) + cafe;              // choose cafe
        dp[i][2] = max(dp[i-1][0],dp[i-1][1]) + bakery;            // choose bakery
    }

    int result = max(dp[n-1][0],max(dp[n-1][1],dp[n-1][2]));
    cout << result;
}