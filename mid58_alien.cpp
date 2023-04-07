#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int n,a,b,x,y,r,difx,dify,dif,count=0;
    cin >> n >> a>> b>>r;
    r=r*r;
    for(int i=0;i<n;i++){
        cin >> x >> y;
        difx=x-a;
        dify=y-b;
        dif=pow(difx,2)+pow(dify,2);
        if(dif<=r)
            count++;
    }  
    cout << count;
}