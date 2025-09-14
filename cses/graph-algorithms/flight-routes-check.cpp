#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n);
    vector<vector<int>> radj(n);
    vector<bool> visited(n, false);
    vector<bool> rvisited(n, false);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;

        adj[a].push_back(b);
        radj[b].push_back(a);
    }

    // first bfs
    queue<int> q;
    q.push(0);
    visited[0] = true;

    while (!q.empty()) {
        int curr_node = q.front();
        q.pop();
        
        for (int node : adj[curr_node]) {
            if (!visited[node]) {
                visited[node] = true;
                q.push(node);
            }
        }
    }

    queue<int> q2;
    q2.push(0);
    rvisited[0] = true;

    while (!q2.empty()) {
        int curr_node = q2.front();
        q2.pop();
        
        for (int node : radj[curr_node]) {
            if (!rvisited[node]) {
                rvisited[node] = true;
                q2.push(node);
            }
        }
    }

    bool valid = true;
    for (int j = 0; j < n; j++) {
        if (visited[j] == false) {
            cout << "NO" << "\n";
            cout << 1 << " " << ++j << "\n";
            valid = false;
            break;
        }
        if (rvisited[j] == false) {
            cout << "NO" << "\n";
            cout << ++j << " " << 1 << "\n";
            valid = false;
            break;
        }
    }
    

    if (valid) {
        cout << "YES" << "\n";
    }
}