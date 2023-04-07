#include<bits/stdc++.h>
using namespace std;

const int MAX_N = 3500;
int bridge1[MAX_N];
int bridge2[MAX_N];
int bridge2_index[MAX_N];
int dp[MAX_N];

int main(){
    int n;
    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> bridge1[i];
    }
    for (int i=1; i<=n; i++){
        cin >> bridge2[i];
        bridge2_index[bridge2[i]] = i;
    }
    dp[1] = 1;
    for (int i=2; i<=n; i++){
        int now = bridge2_index[bridge1[i]];
        int check = 1;
        int save_dp = -1e9;
        for (int j=1; j<i; j++){
            if (now > bridge2_index[bridge1[j]]){
                check = 0;
                if (dp[j] > save_dp){
                    save_dp = dp[j];
                }
            }
        }
        if (check){
            dp[i] = 1;
        }else{
            dp[i] = save_dp+1;
        }
    }   
    int result = -1e9;
    for (int i=1; i<=n; i++){
        result = max(result, dp[i]);
    }   
    cout << result << '\n';
}