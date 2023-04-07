#include <iostream>
#include <algorithm>

using namespace std;

int couting(int x ,int y,int price[],int n){
    int count=0;

    // cout <<"\n"<< x << " " << y <<"\n";
    for(int i = 0;i<n;i++){
        if(x>=price[i]){
            if(price[i]>=y){
            x-=price[i];
            count++;
            }
        }
    }
    return count;
}

int main() {
    int n,q,x,y,sum;

    cin >> n >> q;
    int price[n];
    for(int i = 0; i < n; i++) {
        cin >> price[i];
    }
    sort(price, price + n);
    for(int i = 0; i < n; i++) {
        // cout << price[i] << " ";
    }

    for(int i=0;i<q;i++){
        cin >> x>>y;
        sum =couting(x,y,price,n);
        cout << sum<<"\n";
    }

    return 0;
}

// 5 4 10 7 9 2 13 20 0 1 0 41 0 20 5

// 5 10 10 10 10 10 20 100 0 30 0 30 15 100 15 20 10 20 11 30 1 30 21 9 0 19 20