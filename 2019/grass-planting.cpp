#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

vector<vector<int>> adj;
vector<pair<int, int>> num_children;
vector<int> depth;

int max_children = 0;

void dfs(int node) {
    num_children[node] = {adj[node].size(), depth[node]};

    for (int child : adj[node]) {
        depth[child] = depth[node] + 1;
        dfs(child);
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

    for (int i = 0; i < N - 1; i++) {
        int a, b;
        fin >> a >> b;

        a--; b--;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(0);

    sort(num_children.begin(), num_children.end());

    if (num_children[0].second >= 2) {
        fout << num_children[0].first + 2 << "\n";
    } else {
        fout << num_children[0].first + 1;
    }
}