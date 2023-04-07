#include <iostream>
#include <cstring>
using namespace std;

const int MAXN = 25;

char area[MAXN][MAXN];
int visit[MAXN][MAXN];
int n, q;

bool walk(int i, int j, int k, int p, bool door_check){
    visit[i][j] = 1;
    if (i == k && j == p){
        return true;
    }
    bool status = false;
    if (i < n && area[i+1][j] != '#' && visit[i+1][j] == 0 ){
        if (area[i+1][j] == 'O' && door_check == 0 ){
            status = walk(i+1,j,k,p,1);
        } else if (area[i+1][j] == '.'){
            status = walk(i+1,j,k,p,door_check);
        }
    }
    if (!status && i >= 0 && area[i-1][j] != '#' && visit[i-1][j] == 0){
        if(area[i-1][j] == 'O' && door_check == 0){
            status = walk(i-1,j,k,p,1);
        } else if ((area[i-1][j] == '.')){
            status = walk(i-1,j,k,p,door_check);
        }
    }
    if (!status && j >= 0 && area[i][j-1] != '#' && visit[i][j-1] == 0){
        if(area[i][j-1] == 'O' && door_check == 0){
            status = walk(i,j-1,k,p,1);
        } else if (area[i][j-1] == '.'){
            status = walk(i,j-1,k,p,door_check);
        }
    }
    if (!status && j < n && area[i][j+1] != '#' && visit[i][j+1] == 0){
        if(area[i][j+1] == 'O' && door_check == 0){
            status = walk(i,j+1,k,p,1);
        } else if (area[i][j+1] == '.'){
            status = walk(i,j+1,k,p,door_check);
        }
    }
    return status;
}

int main(){
    cin >> n >> q;
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            cin >> area[i][j];
        }
    }
    for (int t=0;t<q;t++){
        int i,j,p,k;
        bool door = false;
        memset(visit, 0, sizeof(visit));
        cin >> i >> j >> k >> p;
        bool status = walk(i-1,j-1,k-1,p-1,door);
        if (status){
            printf("yes\n");
        } else{
            printf("no\n");
        }
    }
    return 0;
}