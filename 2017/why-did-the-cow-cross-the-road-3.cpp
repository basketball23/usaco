#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <utility>

using namespace std;

int N, K, R, distant_pairs = 0;
map<pair<int, int>, vector<pair<int, int>>> adjMap;
vector<vector<int>> grid;
vector<vector<bool>> visited;

int main() {
    ifstream fin("countcross.in");
    ofstream fout("countcross.out");

    fin >> N >> K >> R;

    grid.resize(N, vector<int>(N, 0));
    visited.resize(N, vector<bool>(N, false));


    for (int i = 0; i < R; i++) {
        int a, b, c, d;
        fin >> a >> b >> c >> d;
        adjMap[{a, b}].push_back({c, d});
    }

    for (int i = 0; i < K; i++) {
        int x_val, y_val;
        fin >> x_val >> y_val;
        grid[x_val][y_val] = 1;
    }

    

}