#include<bits/stdc++.h>
using namespace std;
int n,q;
pair<pair<int,int>,int> shop[100005];
int save_home[100005];

int main(){
    cin >> n >> q;
    for (int i=0;i<n;i++){
        int home,price,order;
        cin >> home >> price >> order ;
        shop[i] = {{home,price},order};
    }
    for (int i=0;i<n;i++){
        save_home[i] = shop[i].first.first;
    }
    sort(save_home,save_home+n);
    sort(shop,shop+n);
    
    for (int i=0;i<q;i++){ 
        int buy,check_price=1e9,status=0,j=0,savej=0;
        cin >> buy;
        int buy_now = (upper_bound(save_home,save_home+n,buy)-save_home); 
        for (int j=buy_now-10;j<=buy_now+10;j++){
            if (j < 0){
                continue;
            }
            if (j > n){
                break;
            }
            if (abs(shop[j].first.first - buy) <= 5 && shop[j].first.second < check_price && shop[j].second != 0){  
                status = 1;
                check_price = shop[j].first.second;
                savej = j;
            }
        }
        if (status){
            shop[savej].second--;
            printf("%d\n",check_price);
        }else{
            printf("%d\n",0);
        }
    }
}