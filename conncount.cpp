#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 100010;

int m,n;
vector<int> adj[MAX_N];
int deg[MAX_N];

void read_input()
{
  cin >> n >> m;
  for(int i = 0; i < n; i++)
    deg[i] = 0;
  
  for(int i = 0; i < m; i++) {
    int u,v;
    cin >> u >> v; u--; v--;

    adj[u].push_back(v);
    adj[v].push_back(u);
    deg[u]++;
    deg[v]++;
  }
}

bool seen[MAX_N];
int layer[MAX_N];

void init()
{
  for(int u = 0; u < n; u++) {
    seen[u] = false;
    layer[u] = -1;
  }
}

void bfs(int s)
{
  vector<int> current_layer;
  vector<int> next_layer;

  current_layer.push_back(s);
  seen[s] = true;
  layer[s] = 0;
  
  while(true) {
    for(auto i=current_layer.begin(); i!=current_layer.end(); i++) {
      int u = *i;
      for(int d=0; d<deg[u]; d++) {
        int v = adj[u][d];
        if(!seen[v]) {
          next_layer.push_back(v);
          seen[v] = true;
          layer[v] = layer[u] + 1;
        }
      }
    }
    if(next_layer.size() == 0)
      break;

    current_layer = next_layer;
    next_layer.clear();
  }
}

int main()
{
  int count =0;
  read_input();
  init();
  for(int i=0;i<n;i++){
    if(!seen[i]){
      bfs(i);
      count++;
    }
  }
  cout << count;
  
}