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
    bool connected = false;
    vector<int> values_that_work;

    for (int i = 0; i < n; i++) {
        queue<int> q;
        q.push(i);
        visited[i] = true;
        connected = false;

        while (!q.empty()) {
            int curr_node = q.front();
            q.pop();

            // can binary search

            int lo = 0;
            int hi = values_that_work.size();

            while (lo < hi) {
                int mid = lo + (hi - lo)/2;
                if (values_that_work[mid] == curr_node) {
                    connected = true;
                    break;
                } else if (values_that_work[mid] > curr_node) {
                    hi = mid - 1;
                } else {
                    lo = mid + 1;
                }
            }
            
            for (int node : adj[curr_node]) {
                if (!visited[node]) {
                    visited[node] = true;
                    q.push(node);
                }
            }
        }

        if (connected) {
            values_that_work.push_back(i);
            fill(visited.begin(), visited.end(), false);
            continue;
        }

        for (int j = 0; j < n; j++) {
            if (visited[j] == false) {
                cout << "NO" << "\n";
                cout << ++i << " " << ++j << "\n";
                valid = false;
                break;
            }
        }

        if (!valid) {
            break;
        }

        values_that_work.push_back(i);
        fill(visited.begin(), visited.end(), false);
    }

    if (valid) {
        cout << "YES" << "\n";
    }
}