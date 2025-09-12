#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;


vector<vector<pair<int, int>>> adj;
vector<bool> visited;
vector<int> cows;

bool wormholeWorks(int size) {

    for (int i = 0; i < cows.size(); i++) {
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

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int N, M;
    cin >> N >> M;

    adj.resize(N);
    visited.resize(N, false);
    cows.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> cows[i];
    }
    /*
    IMPORTANT: vector is zero indexed, but the problem is 1-indexed. Make sure to convert
    */

    vector<int> weights;
    for (int i = 0; i < M; i++) {
        int a, b, w;
        cin >> a >> b >> w;

        a--; b--;

        adj[a].push_back({b, w});
        adj[b].push_back({a, w});

        weights.push_back(w);
    }
    sort(weights.begin(), weights.end());

    int max_min = -1;

    // Use binary search to determine the wormhole width: find the maximum value that works (function looks like: false, false, false, true true)
    // run bfs over EVERY node, to find its path to the target with the maximum min width

    int lo = 0;
    int hi = weights.size() - 1;

    while (lo < hi) {
        int mid = lo + (hi - lo)/2;

        if (wormholeWorks(weights[mid])) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
        fill(visited.begin(), visited.end(), false);
    }
    
    cout << weights[lo] << "\n";
}