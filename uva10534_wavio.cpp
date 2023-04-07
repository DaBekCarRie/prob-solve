#include<bits/stdc++.h>
using namespace std;

const int MAXN = 10010;
int demo[MAXN];
int save_behind[MAXN];
int save_next[MAXN];
int kvec_next[MAXN];
int kvec_behind[MAXN];

int main(){
    int n;
    while(cin >> n){ 
        for (int i=0;i<n;i++){
           demo[i] = 0;
           save_next[i] = 0;
           save_behind[i] = 0;
        }
        
        for (int i=0;i<n;i++){
            cin >> demo[i];
        }

        int len_next = 0;
        for (int i=0;i<n;i++){
            int index = lower_bound(kvec_next, kvec_next+len_next, demo[i]) - kvec_next;
            if (index == len_next){
                kvec_next[len_next++] = demo[i];
            }else{
                kvec_next[index] = demo[i];
            }    
            save_next[i]= (index+1);
        }

        int len_behind = 0;
        for (int i=n-1;i>=0;i--){
            int index = lower_bound(kvec_behind, kvec_behind+len_behind, demo[i]) - kvec_behind;
            if (index == len_behind){
                kvec_behind[len_behind++] = demo[i];
            }else{
                kvec_behind[index] = demo[i];
            }    
            save_behind[i]= (index+1);
        }

        int sum_next=0,sum_behind=0;
        for (int i=0;i<n;i++){
            sum_next+=save_next[i];
            sum_behind+=save_behind[i];
        }

        if (sum_next == n || sum_behind == n){
            cout << 1 << '\n';
            continue;
        }

        int result = 0;
        for (int i=0;i<n;i++){
            result = max(result,min(save_next[i],save_behind[i])*2-1);
        }
        cout << result << '\n';
    }
}