#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

vector<vector<int>> adj;
vector<pair<int, int>> num_children;
vector<int> depth;
vector<bool> visited;

int max_children = 0;

void dfs(int node) {
    // Todo: Remove depth vector, using only num_children.second in place of depth instead
    num_children[node].second = depth[node];
    visited[node] = true;

    for (int child : adj[node]) {
        if (!visited[child]) {
            num_children[node].first++;

            visited[child] = true;
            depth[child] = depth[node] + 1;
            dfs(child);
        }
    }
}

int main() {
    ifstream fin("planting.in");
    ofstream fout("planting.out");

    int N;
    fin >> N;

    adj.resize(N);
    num_children.resize(N);
    depth.resize(N);
    visited.resize(N, false);

    for (int i = 0; i < N - 1; i++) {
        int a, b;
        fin >> a >> b;

        a--; b--;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(0);

    sort(num_children.rbegin(), num_children.rend());

    if (num_children[0].second >= 2) {
        fout << num_children[0].first + 2 << "\n";
    } else {
        fout << num_children[0].first + 1;
    }
}