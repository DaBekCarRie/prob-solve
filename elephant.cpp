#include<bits/stdc++.h>
using namespace std;

int arr[100100];
int dp[100100];
int result = -1e9;
int findmaxdp;

int main(){
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> arr[i];
    if(i<3){continue;}
    
    findmaxdp=max(dp[i-1],arr[i]+dp[i-3]);
		dp[i] = findmaxdp;
		result = max(result,dp[i]);
	}
    cout << result;
}