#include<bits/stdc++.h>
using namespace std;

int main(){
    while(1){
        int n;
        cin >> n;
        if (n == 0){
            break;
        }
        int demo[n];
        for(int i=0;i<n;i++){
            cin >> demo[i];
        }
        sort(demo,demo+n);
        for(int i=0;i<n;i++){
            if(i>0){
                cout << ' ';
            }
            cout << demo[i] ;
        }
        cout << '\n';
    }
}