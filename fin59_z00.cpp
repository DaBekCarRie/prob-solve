#include<iostream>
using namespace std;

int main(){
    int r,c,b,t,n,count=1,a,checkzero=0;
    cin >> r >>c >>b >>t;
    int left=b;
    int space[r][c];
    for (int i =0 ;i<r;i++){
        for(int j=0;j<c;j++){
            cin >> space[i][j];
        }
    }
    for (int i =0 ;i<r;i++){
        checkzero=0;
        for(int j=0;j<c;j++){
            if(space[i][j]!=0){
                checkzero+=1;
            }
            for(int k=0;k<space[i][j];k++){
                // cout << "start = " << left<< " t = " << t << " index " << i << j <<"\n";
                if(left>=t){

                    // cout << "if" "\n";
                    left-=t;
                }
                else{
                    left=b;
                    // cout << "else" << "\n";
                    count+=1;
                    left-=t;
                }
                // cout << "end = " << left<< " t = " << t<< "count = " << count  << "\n";

            }
        }
        if(checkzero==0){
            count-=1;
        }
        count+=1;
        left=b;
        // cout << "count = " << count <<"\n";
    }
    count-=1;
    cout<<count;
    
}
// 2 2 100 1 10 5 3 4
// 3 4 11 4 10 5 1 1 3 4 0 0 0 0 0 0