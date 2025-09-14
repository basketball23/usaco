#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n);
    vector<bool> visited(n, false);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;

        adj[a].push_back(b);
    }

    bool valid = true;
    for (int i = 0; i < n; i++) {
        queue<int> q;
        q.push(i);
        visited[i] = true;

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


        for (int j = 0; j < n; j++) {
            if (visited[j] == false) {
                cout << "NO" << "\n";
                cout << j << " " << i << "\n";
                valid = false;
                break;
            }
        }

        if (!valid) {
            break;
        }

        fill(visited.begin(), visited.end(), false);
    }

    if (valid) {
        cout << "YES" << "\n";
    }
}