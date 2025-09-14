#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;


vector<vector<pair<int, int>>> adj;
vector<bool> visited;
vector<int> cows;
vector<int> weights;

bool wormholeWorks(int wormhole_size) {

    for (int i = 0; i < cows.size(); i++) {
        
        bool found = false;
        int target = --cows[i];

        
        queue<int> q;
        q.push(i);
        visited[i] = true;

        while (!q.empty()) {
            int curr_node = q.front();
            q.pop();

            if (curr_node == target) {
                found = true;
                break;
            }

            for (pair<int, int> neighbor : adj[curr_node]) {
                if (!visited[neighbor.first] && neighbor.second >= wormhole_size) {
                    visited[neighbor.first] = true;
                    q.push(neighbor.first);
                }
            }
        }
        

        if (!found) {
            return false;
        }
        fill(visited.begin(), visited.end(), false);
    }

    return true;
}

int main() {
    //ifstream cin("wormsort.in");
    //ofstream cout("wormsort.out");
    
    int N, M;
    cin >> N >> M;

    adj.resize(N);
    visited.resize(N, false);
    cows.resize(N);
    weights.resize(M);

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

        weights[i] = w;
    }
    sort(weights.begin(), weights.end());

    // Use binary search to determine the wormhole width: find the maximum value that works (function looks like: true, true, true, false, false)
    // this is too slow: run bfs over EVERY node, to find its path to the target with the maximum min width

    int lo = 0;
    int hi = weights.size() - 1;

    while (lo < hi) {
        int mid = lo + (hi - lo)/2 + 1;

        if (wormholeWorks(weights[mid])) {
            lo = mid;
        } else {
            hi = mid - 1;
        }
    }

    bool sorted = true;
    for (int i = 0; i < N; i++) {
        if (cows[i] != i + 1) {
            sorted = false;
            break;
        }
    }
    
    if (sorted) {
        cout << -1 << "\n";
    } else {
        cout << weights[lo] << "\n";
    }
}