#include <iostream>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
vector<pair<int, int>> edges;

/*
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
*/

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

    /*
    // Algo: use a greedy approach - if odd, flip one edge to make it even
    if (m % 2 != 0) {
        cout << "IMPOSSIBLE" << "\n";
    } else {

        dfs(0);

        for (int i = 0; i < m; i++) {
            cout << edges[i].first << " " << edges[i].second << "\n";
        }
    }
    */

    queue<int> q;
    q.push(0);
    visited[0] = true;

    while (!q.empty()) {
        int curr_node = q.front();
        q.pop();

        visited[curr_node] = true;

        for (int child : adj[curr_node]) {
            if (!visited[child]) {
                q.push(child);
            }
        }
    }
}