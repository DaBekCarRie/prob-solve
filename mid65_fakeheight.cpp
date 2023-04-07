#include<iostream>
#include <cmath>
using namespace std;

int sumDif(long long difright [100010],long long arr [100010],int n,long long right [100010]){
    long long sum=0;
    for(int i=1;i<n+1;i++){   
        if(i==n){
            difright[i]=0;
            continue;
        }
        // cout << "arr " << arr[i] << "right " << arr[i+1] ;
        difright[i]=abs(arr[i]-arr[i+1]);
        // cout << "dif " << difright[i] << "\n";
        sum+=difright[i];
        // cout << "sum " << i << "is " << sum << "\n";
    }
    for(int i=1;i<n+1;i++){
        // cout << " difright" << difright[i]<<"\n";
    }
    return sum;
}

int main(){
    int n;
    long long x;
    long long arr [100010];
    long long right [100010];
    long long difright [100010];
    cin >> n;
    cin >> arr[1];
    long long sum=0,min;

    for(int i=2;i<n+1;i++){
        cin >> x;
        arr[i]=x;
        right[i-1]=arr[i];
        
    }
    // for(int i=1;i<n+1;i++){
    //     cout << arr[i] << " ";
    // }
    // cout << "\n";
    for(int i=1;i<n+1;i++){
        // cout << " right" << right[i] << "\n";
    }

    min = sumDif(difright,arr,n,right);
    for(int i = 1;i<n+1;i++){
        long long mem = arr[i];
        // if(i==3){
        // cout << "round " << i << "\n";
        for(int j=1;j<n+1;j++){
            if(abs(i-j)<=1){
                continue;
            }
            arr[i]=arr[j];
            // for(int i=1;i<n+1;i++){
            //     cout << arr[i] << " ";
            // }
            // cout << "\n";
            sum = sumDif(difright,arr,n,right);
            // cout << "sum is -->" << sum <<"\n";
            arr[i]=mem;
            if(sum<min){
                min=sum;
            }
        }
        // }
    }
    cout << min ;
}