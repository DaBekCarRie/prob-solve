#include<iostream>
#include<list>
using namespace std;
void print(list<int>& mylist,int index)
{
      for (auto element : mylist) 
    {
        cout << element << '\n';
    }
}
  void print(list<int>* arr, int n)
{
    for (int i = 1; i < n+1; i++) 
    {   
        if(arr[i].size()!=0)
            print(arr[i], i);
    }
}
int main(){
    int m,value,platform,ii,jj,v1,v2;
    char c;
    list<int> arr[100100];
    list<int>::iterator it;
    cin >> m;
    for(int i=1;i<m+1;i++){
        cin >> c >> v1   >> v2;     
        if(c=='N'){
            platform=v2;value=v1;
            arr[platform].push_back(value);
        }
        if(c=='M'){
            ii=v1;jj=v2;
            while (1)
            {   
                if(arr[ii].empty())
                    break;
                value=arr[ii].front();
                arr[ii].pop_front();
                //cout << value << '\n';
                arr[jj].push_back(value);
                
            }
            
        }
    }
    print(arr, m);
    return 0;
}