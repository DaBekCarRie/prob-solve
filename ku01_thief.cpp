#include<iostream>
using namespace std;
int main(){
    long int n,k,t,position=1,i=1;
    cin >> n >> k >> t;
    while(1){
        position=1+i*k;
        position=position%n;
        //cout << position<< '\n';
        if(position==1 || position==t){
            if(position==t)
                i+=1;
            cout << i;
            break;
        }
        //cout << i<< ' ';
        i++;
    }
    return 0;
}