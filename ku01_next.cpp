#include<iostream>
using namespace std;
int main(){
    long int n,a,k,i,count=0,endcheck,max=0;
    int arr[100100];
    
    cin >> n;
    for(int i=1;i<n+1;i++){
        cin >>a;
        arr[i]=a;
    }
    int x;
    for(int j=1;j<n+1;j++){
        count=0;
            x=arr[j];
            //cout<< x << "is x \n";
            k=j;
            endcheck=1;
        while(endcheck!=0){
            x=arr[k];
            if(j==x)
                endcheck=0;
            //cout<< x << "is x2 \n";
            k=arr[k];
            count++;
            //cout<< count<<'\n';
        }
        if(count>max)
            max=count;


    }
    for(i=1;i<n+1;i++){
        //cout << arr[i] << " " << '\n';
    }
    //cout << count<< " "<<max;
    cout <<max;
    return 0;
}