#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int num_vertices, num_edges;
vector<int> adjacency_list[150000];
int in_degree[150000];

int main() {
    cin >> num_vertices >> num_edges;

    for (int i = 0; i < num_edges; i++) {
        int vertex_from, vertex_to;
        cin >> vertex_from >> vertex_to;
        adjacency_list[vertex_from].emplace_back(vertex_to);
        in_degree[vertex_to]++;
    }
    queue<int> q;
    for (int i = 1; i <= num_vertices; i++) {
        if (in_degree[i] == 0) {
            q.push(i);
        }
    }
    if (q.empty())
        cout << "no";
    while (!q.empty()) {
        int current_vertex = q.front();
        cout << current_vertex << "\n";
        q.pop();
        for (int i = 0; i < adjacency_list[current_vertex].size(); i++) {
            in_degree[adjacency_list[current_vertex][i]]--;
            if (in_degree[adjacency_list[current_vertex][i]] == 0) {
                q.push(adjacency_list[current_vertex][i]);
            }
        }
    }
    return 0;
}