#include<iostream>
using namespace std;
int main(){
    int n,m,r;
    cin >> n >> m;
    int shows[n+1];
    int state[n+1];
    int maxs[n+1];

    for(int i =1; i<n+1;i++){
        shows[i]=0;
        state[i]=0;
        maxs[i]=0;
    }
    for(int i =1; i<m+1;i++){
        cin >> r;
        shows[r]+=1;
        maxs[r]=shows[r];
        // cout << "index = " << i  << " state[" << r << "] =" << state[r];
        // cout << " i-state[r] = " << i-state[r] ;
        if(i-state[r]>6 && state[r]!=0){
            shows[r]=0;
            maxs[r]-=1;
        }
            state[r]=i;
        // cout << " show[" << r << "] = " << shows[r] << " maxs[" << r << "] = " << maxs[r]<< "\n";
    }

    int max=0;
    for (int i = 1; i<n+1;i++){
        if(i<5){
            // cout << "shows[i] = " << shows[i] << "\n"; 
        }
        if(maxs[i]>max){
            max = maxs[i];
        }
    }
    for (int i = 1; i<n+1;i++){
        if(maxs[i]==max){
        cout << i << " " << maxs[i];
        break;
        }
        
    }
}
// 5 14 3 3 3 3 1 2 2 2 2 1 3 4 2 1
// 5 10 3 3 3 3 1 2 2 2 2 1
// 9 19 1 1 3 2 3 3 4 4 5 2 4 3 6 7 8 9 1 2 3