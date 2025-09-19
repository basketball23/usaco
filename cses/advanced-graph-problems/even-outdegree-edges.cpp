#include <iostream>
#include <vector>
#include <utility>

using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
vector<pair<int, int>> edges;

void dfs(int node) {
    visited[node] = true;
    // more logic here


    for (int child : adj[node]) {
        if (!visited[child]) {
            int child_degree = adj[child].size();

            if (child_degree % 2 != 0) {
                edges.push_back({child, node});
            } else {
                edges.push_back({node, child});
            }

            dfs(child);
        }
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    adj.resize(n);
    visited.resize(n);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    // Algo: use a greedy approach - if odd, flip one edge to make it even
    if (m % 2 != 0) {
        cout << "IMPOSSIBLE" << "\n";
    } else {

        dfs(0);

        for (int i = 0; i < m; i++) {
            cout << edges[i].first << " " << edges[i].second << "\n";
        }
    }
}