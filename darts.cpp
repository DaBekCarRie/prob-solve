#include<iostream>
#include<cmath>
using namespace std;
int main(){
    float n,x,y,r,score=0,count;
    cin >>n;
    for(int i=0;i<n;i++){
        cin >> x >> y;
        x=pow(x,2);
        y=pow(y,2);
        r=sqrt(x+y);
        if(r<=2)
            count=5;
        else if (r<=4)
        {
            count=4;
        }
        else if (r<=6)
        {
            count=3;
        }
        else if (r<=8)
        {
            count=2;
        }
        else if (r<=10)
        {
            count=1;
        }
        else
            count=0;
        score=score+count;
        //cout<<score<<" \n";
        
    }
    //cout<<'\n';
    //cout << x <<" "<< y<< " "<< r<<'\n';
    cout << score;
    return 0;
}