#include<iostream>
using namespace std;
int main(){
    int brigde[350];
    int n,a,b,count,l;
    cin >> l >> n;
    
    for(int i=0;i<l;i++){
        brigde[i]=0;
    }
    for(int i=0;i<n;i++){
        cin >> a >> b;
        count=0;
        int k=a;
        while(k<b){
            k++;
            brigde[k]++;
            count++;
        }
    //cout <<"range" << count << "\n";
    }
    int max=0;
    for(int j=0;j<l;j++){
        //cout << j << " " << brigde[j] << "\n";
        if(brigde[j]>max)
            max = brigde[j];
    }
    cout << max;
}