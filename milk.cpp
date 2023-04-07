#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> edges;

int n, m, parent[111111];

int findParent(int node)
{
    if (node == parent[node])
    {
        return node;
    }
    return parent[node] = findParent(parent[node]);
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
    }
    for (int i = 1; i <= m; i++)
    {
        int a, b;
        char menu;
        cin >> menu >> a >> b;
        if (menu == 'c')
        {
            parent[findParent(a)] = findParent(b);
        }
        else
        {
            if (findParent(a) == findParent(b))
            {
                cout << "yes\n";
            }
            else
            {
                cout << "no\n";
            }
        }
    }
}