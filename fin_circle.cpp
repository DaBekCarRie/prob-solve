#include<iostream>
using namespace std;

int main(){
    int n,h,x,position,max=0,count=0,life;
    cin >> n >> h;
    int bg[n];
    for(int i =0;i<n;i++){
        cin >> bg[i];        
    }

    for(int i =0;i<n;i++){
        life=h;
        position=i;
        count = 0;
        while (1)
        {
            if(life>=bg[position]){
                life-=bg[position];
                count+=1;
                
            }
            else{
                if(count>max){
                    max=count;
                }
                break;
            }
            position+=1;
            if(position>n){
                position=position%n;
            }
        }
       
    }
    if(max>=n)
        max = n;
    cout << max;

}
// 5 10 5 4 3 2 7