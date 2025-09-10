#include <iostream>
#include <vector>

using namespace std;

vector<bool> visited;
vector<vector<int>> adj;
vector<int> unconnected;

void dfs(int node) {
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            visited[neighbor] = true;
            dfs(neighbor);
        }
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;

    visited.resize(n, false);
    adj.resize(n);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        
        // Zero indexing
        a--; b--;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            unconnected.push_back(i + 1);
            dfs(i);
        }
    }

    int num_cities = unconnected.size();
    if (num_cities > 1) {
        cout << num_cities - 1 << "\n";
        for (int i = 1; i < num_cities; i++) {
            cout << unconnected[0] << " " << unconnected[i] << "\n";
        }
    } else {
        cout << 0 << "\n";
    }
}