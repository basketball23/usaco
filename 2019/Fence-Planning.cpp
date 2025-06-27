#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <utility>
#include <cmath>
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
vector<pair<int, int>> cows; // 2D vector to store cow positions

int max_x = 0;
int max_y = 0;
int min_x = 100000000;
int min_y = 100000000;
int perimeter = 4 * 100000000; // Initialize perimeter to a large value

void dfs(int node) {
    for (int n : adj[node]) {
        if (!visited[n]) {
            visited[n] = true; // Mark the node as visited

            max_x = max(max_x, cows[n].first);
            max_y = max(max_y, cows[n].second);
            min_x = min(min_x, cows[n].first);
            min_y = min(min_y, cows[n].second);

            dfs(n);
        }
    }

}

int main() {
    ifstream fin("fenceplan.in");
    ofstream fout("fenceplan.out");

    int N, M;
    fin >> N >> M;

    adj.resize(N);
    visited.resize(N, false);
    cows.resize(N); // Resize to hold N cows with 2 attributes each (x, y)
    
    for (int i = 0; i < N; i++) {
        int x, y;
        fin >> x >> y;
        cows[i] = make_pair(x, y); // Store cow positions as pairs
    }

    for (int i = 0; i < M; i++) {
        int a, b;
        fin >> a >> b;
        
        a--; // Convert to 0-based index
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a); // Undirected edges
    }

    for (int i = 0; i < N; i++) {
        max_x = 0;
        max_y = 0;
        min_x = 100000000;
        min_y = 100000000;
        if (!visited[i]) {
            visited[i] = true; // Mark the node as visited
            max_x = cows[i].first;
            min_x = cows[i].first;
            max_y = cows[i].second;
            min_y = cows[i].second;
            dfs(i); // Perform DFS to visit all connected nodes
        }

        if (abs(max_x - min_x) * 2 + abs(max_y - min_y) * 2 < perimeter) {
            perimeter = abs(max_x - min_x) * 2 + abs(max_y - min_y) * 2; // Update perimeter if smaller
        }
    }

    fout << perimeter << endl; // Output the minimum perimeter
    return 0;
}