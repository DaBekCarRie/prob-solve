#include<iostream>
using namespace std;
int main(){
    int n,a,b,count=0,max=0;
    int arr[100100];
    cin >> n;
    for(int i=1;i<n+1;i++){
        cin >> a;
        if(a>count)
            count=a;
        arr[a]++;
    }
    //cout << count;
    for (int j=0;j<count+1;j++){
        if(arr[j]>max)
            max = arr[j];
        //cout << j << " is " << arr[j] << '\n';
    }
    //cout << arr[a] << " "<<arr[b];
    cout << max;
}