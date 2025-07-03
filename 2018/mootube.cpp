#include <iostream>
#include <fstream>
#include <vector>
#include <utility>

using namespace std;

int N, Q, video_count = 0;
vector<vector<pair<int, int>>> connections;
vector<int> video_suggestions;
vector<bool> visited;

void dfs(int node, int min_relevance) {
    /*
    DFS with each query video as the root
    Recurse through the tree and sum the video count as you go
    */
    visited[node] = true;

    for (auto& i : connections[node]) {
        if (!visited[i.first] && i.second >= min_relevance) {
            video_count++;
            dfs(i.first, min_relevance);
        }
    }
}

int main() {
    ifstream fin("mootube.in");
    ofstream fout("mootube.out");

    fin >> N >> Q;

    // resizing
    connections.resize(N);
    video_suggestions.resize(Q, 0);
    visited.resize(N, false);

    // inputting
    for (int i = 0; i < N - 1; i++) {
        int p, q, r;
        fin >> p >> q >> r;

        p--; q--;

        connections[p].push_back({q, r});
        connections[q].push_back({p, r});
    }

    // iterate through each query and DFS
    for (int i = 0; i < Q; i++) {
        int k, v;
        fin >> k >> v;
        int relevance = k;

        v--;
        video_count = 0;
        fill(visited.begin(), visited.end(), false);

        dfs(v, relevance);
        video_suggestions[i] = video_count;
    }

    // output
    for (int i = 0; i < video_suggestions.size(); i++) {
        fout << video_suggestions[i] << endl;
    }
}