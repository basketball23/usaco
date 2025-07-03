#include <iostream>
#include <fstream>
#include <vector>
#include <utility>

using namespace std;

int N, Q, video_count = 0;
vector<vector<pair<int, int>>> connections;
vector<int> video_suggestions;
vector<bool> visited;

void dfs(int node, int current_depth, int min_relevance) {

    visited[node] = true;

    for (auto i : connections[node]) {
        if (current_depth + i.second >= min_relevance) {
            video_count++;
        }
        if (visited[i.first] == false) {
            dfs(i.first, current_depth + i.second, min_relevance);
        }

    }
}

int main() {
    ifstream fin("mootube.in");
    ofstream fout("mootube.out");

    fin >> N >> Q;

    connections.resize(N, vector<pair<int, int>>(N));
    video_suggestions.resize(Q, 0);
    visited.resize(N, false);

    for (int i = 0; i < N - 1; i++) {
        int p, q, r;
        cin >> p >> q >> r;

        connections[p].push_back({q, r});
        connections[q].push_back({p, r});
    }

    for (int i = 0; i < Q; i++) {
        int k, v;
        fin >> k >> v;
        int relevance = k;

        video_count = 0;
        fill(visited.begin(), visited.end(), false);

        dfs(v, 0,relevance);
        video_suggestions[i] = video_count;
    }

    for (int i = 0; i < video_suggestions.size(); i++) {
        fout << video_suggestions[i];
        if (i != video_suggestions.size() - 1) {
            fout << " ";
        }
    }
    fout << endl;
}