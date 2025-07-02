#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <map>
#include <utility>

using namespace std;

int N, K, R, close_pairs = 0, distant_pairs, total_pairs, i, j;
map<pair<int, int>, vector<pair<int, int>>> adj_map;
vector<vector<int>> grid;
vector<vector<bool>> visited;

void flood(int r, int c) {

    if(r < 0 || r >= N || c < 0 || c >= N || visited[r][c] == true) {
        return;
    }

    visited[r][c] = true;

    if (r != i || c != j) {
        if (grid[r][c] == 1) {
            close_pairs++;
        }
    }

    pair<int, int> target_pair = {r - 1, c};
    auto it = find(adj_map[{r, c}].begin(), adj_map[{r, c}].end(), target_pair);
    if (it == adj_map[{r, c}].end()) {
        flood(r - 1, c);
    }
    target_pair = {r + 1, c};
    it = find(adj_map[{r, c}].begin(), adj_map[{r, c}].end(), target_pair);
    if (it == adj_map[{r, c}].end()) {
        flood(r + 1, c);
    }
    target_pair = {r, c - 1};
    it = find(adj_map[{r, c}].begin(), adj_map[{r, c}].end(), target_pair);
    if (it == adj_map[{r, c}].end()) {
        flood(r, c - 1);
    }
    target_pair = {r, c + 1};
    it = find(adj_map[{r, c}].begin(), adj_map[{r, c}].end(), target_pair);
    if (it == adj_map[{r, c}].end()) {
        flood(r, c + 1);
    }
}

int main() {
    ifstream fin("countcross.in");
    ofstream fout("countcross.out");

    fin >> N >> K >> R;

    grid.resize(N, vector<int>(N, 0));
    visited.resize(N, vector<bool>(N, false));


    for (i = 0; i < R; i++) {
        int a, b, c, d;
        fin >> a >> b >> c >> d;
        a--; b--; c--; d--;
        adj_map[{a, b}].push_back({c, d});
        adj_map[{c, d}].push_back({a, b});
    }

    for (i = 0; i < K; i++) {
        int x_val, y_val;
        fin >> x_val >> y_val;
        x_val--; y_val--;
        grid[x_val][y_val] = 1;
    }

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            if (grid[i][j] == 1) {
                for (auto &row : visited) {
                    fill(row.begin(), row.end(), false);
                }
                flood(i, j);
            }
        }
    }

    total_pairs = (K * (K - 1))/2;
    close_pairs /= 2;
    distant_pairs = total_pairs - close_pairs;

    fout << distant_pairs << endl;
}