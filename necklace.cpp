#include<bits/stdc++.h>
using namespace std;

vector<int> l[305000];
int par[305000];

int find(int u) { return par[u] = u == par[u] ? u : find(par[u]); }

int main(){
    int N;
    cin >> N;

    for(int i=1;i<=N;i++){
        l[i].push_back(i);
        par[i] = i;
    }

    for(int i=1;i<N;i++){
        int x,y;
        cin >> x >> y;
        int pary = find(y);
        auto it = find(l[pary].begin(), l[pary].end(), y);
        it++;
        l[pary].insert(it, l[x].begin(), l[x].end());
        par[x] = y;

        if(i==N-1){
            for(auto it : l[pary]){
                cout << it << ' ';
            }cout << endl;
        }
    }
}