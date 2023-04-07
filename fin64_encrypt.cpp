#include <bits/stdc++.h>
using namespace std;

int main(){
int n,s,k,arr[20],temp[20],i,j;
cin >> n >> s;
for(i = 0 ; i < n ; i++)
cin >> arr[i];
if(n < 20){
k=1;
for(i = n ; i < 20 ; i++){
//cout << " add"<< i << " " << k << "\n";
arr[i] = k;
k++;
}
}
  //prit/
  
///rotate
  
for(i = 0 ; i < 20 ; i++){
temp[i] = arr[i];
}
for(j = 0 ; j < 20 ; j++){
arr[(j+s)%20] = temp[j];
}
/* for (int i = 0; i < 20; i++){
    cout << "test?";
cout << arr[i] << " \n";
    }*/
//change to matrix
int matrix[4][5];
k=0;
for(i=0;i<4;i++){
  for(j=0;j<5;j++){
    matrix[i][j]=arr[k];
    k++;
  }
}
//print
  for(j=0;j<5;j++){
    for(i=0;i<4;i++){
      cout << matrix[i][j]<< " ";
    }
  }


}