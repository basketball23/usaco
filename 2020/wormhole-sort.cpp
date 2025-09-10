#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int N, M;
    cin >> N >> M;

    vector<vector<pair<int, int>>> adj(N);
    vector<bool> visited(N);

    vector<int> cows(N);
    for (int i = 0; i < N; i++) {
        cin >> cows[i];
    }
    /*
    IMPORTANT: vector is zero indexed, but the problem is 1-indexed. Make sure to convert
    */

    for (int i = 0; i < M; i++) {
        int a, b, w;
        cin >> a >> b >> w;

        a--; b--;

        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
    }

    int max_min = -1;

    // run bfs over EVERY node, to find its path to the target with the maximum min width
    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            queue<int> q;
            q.push(i);
            visited[i] = true;

            while (!q.empty()) {
                int curr_node = q.front();
                q.pop();

                for (pair<int, int> neighbor : adj[curr_node]) {
                    if (!visited[neighbor.first]) {
                        visited[neighbor.first] = true;
                        q.push(neighbor.first);
                    }
                }
            }
        }
    }
}