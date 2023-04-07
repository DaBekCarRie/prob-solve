#include<bits/stdc++.h>
using namespace std;
int main(){
    int arr[1010];
    int i,n,sum=0,x;
    cin >> n;
    for(i=1;i<n+1;i++){
        cin >> arr[i];
    }
    for(i=2;i<n+1;i++){
        x=arr[i-1]-arr[i];
        //cout << x << " is dif" << arr[i-1] << " " <<arr[i] << "\n";
        if( x>10 && x*10<=700 ){
            sum+=x*10;
        }
        else if(x*10>700){
            sum+=700;
        }
        //cout << sum << " " << i << "\n";
        }
    cout << sum;
}