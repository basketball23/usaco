#include <iostream>

using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
vector<pair<int, int>> edges;

void dfs(int node) {
    visited[node] = true;
    // more logic here

    for (int child : adj[node]) {
        if (!visited[child]) {
            // add logic here

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

    dfs(0);

    for (int i = 0; i < m; i++) {
        cout << edges[i].first << " " << edges[i].second << "\n";
    }
}