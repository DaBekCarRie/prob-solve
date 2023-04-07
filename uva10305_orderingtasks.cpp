#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    while (true) {
        int n, m;
        cin >> n >> m;
        if (n == 0 && m == 0) break;
        
        // Initialization
        vector<int> in_degree(n, 0);
        vector<vector<int>> adj_list(n);
        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            adj_list[a-1].push_back(b-1);
            in_degree[b-1]++;
        }
        
        // Kahn's algorithm
        set<int> s;
        for (int i = 0; i < n; i++) {
            if (in_degree[i] == 0) s.insert(i);
        }
        vector<int> result;
        while (!s.empty()) {
            int x = *s.begin();
            s.erase(s.begin());
            result.push_back(x+1);
            for (int y : adj_list[x]) {
                in_degree[y]--;
                if (in_degree[y] == 0) s.insert(y);
            }
        }
        
        // Output
        if (result.size() == n) {
            for (int x : result) {
                cout << x << " ";
            }
            cout << endl;
        } else {
            cout << "IMPOSSIBLE" << endl;
        }
    }
    return 0;
}