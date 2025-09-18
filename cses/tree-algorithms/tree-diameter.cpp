#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
vector<pair<int, int>> depth;

void dfs(int node) {
    visited[node] = true;

    for (int child : adj[node]) {
        if (!visited[child]) {
            depth[child].first = depth[node].first + 1;
            depth[child].second = child;

            dfs(child);
        }
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n;
    cin >> n;

    adj.resize(n);
    visited.resize(n, false);
    depth.resize(n);

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        
        a--; b--;

        adj[a].push_back(b);
    }

    // Dfs on arbritrary node, obtain max depth

    // Then dfs again on that max depth node, and find the new max depth -> gives you the answer

    dfs(0);
    sort(depth.rbegin(), depth.rend());

    int max_node = depth[0].second;

    // gotta remember i have two ways to fill
    fill(visited.begin(), visited.end(), false);
    depth.assign(n, {0, 0});

    
    dfs(max_node);
    sort(depth.rbegin(), depth.rend());

    cout << depth[0].first << "\n";
}