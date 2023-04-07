#include<iostream>
using namespace std;
int main(){
    int n,a,sum=0,count=0;
    int arr[110];
    int price[100100];
    cin >> n;
    for(int i =1 ;i<n+1;i++){
        cin >> a;
        arr[i]=a;
    }
    for(int i = 0;i<100100;i++){
        price[i]=0;
    }
    for(int i = 1 ;i<n+1;i++){
        sum=0;
        for(int j = i;j<n+1;j++){
            sum+=arr[j];
            price[sum]=1;
        }
    }
    for(int i = 0;i<100100;i++){
        if(price[i]!=0){
            count++;
        }
    }
    cout << count << "\n";
}