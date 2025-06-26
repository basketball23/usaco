#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
vector<vector<int>> cows; // 3D vector to store cow positions and power

int max_count = 0;
int current_count = 0;

void dfs(int node) {
    for (int n : adj[node]) {
        if (!visited[n]) {
            visited[n] = true; // Mark the node as visited
            current_count++;
            dfs(n);
        }
    }
}

int main() {
    ifstream fin("moocast.in");
    ofstream fout("moocast.out");

    int N;
    fin >> N;

    adj.resize(N);
    visited.resize(N, false);
    cows.resize(N, vector<int>(3)); // Resize to hold N cows with 3 attributes each

    for (int i = 0; i < N; i++) {
        int x, y, p;
        fin >> x >> y >> p;
        cows[i][0] = x; // x-coordinate
        cows[i][1] = y; // y-coordinate
        cows[i][2] = p; // power
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i != j) {
                long long dx = cows[i][0] - cows[j][0];
                long long dy = cows[i][1] - cows[j][1];
                long long dist_sq = dx * dx + dy * dy;
                long long power_sq = (long long)cows[i][2] * cows[i][2];
                if (dist_sq <= power_sq) {
                    adj[i].push_back(j);
                }
            }
        }
    }


    for (int i = 0; i < N; i++) {
        fill(visited.begin(), visited.end(), false);

        visited[i] = true; // Start DFS from cow i
        current_count = 1; // Count the starting cow
        dfs(i);
        
        if (current_count > max_count) {
            max_count = current_count; // Update max_count if current count is greater
        }
    }

    fout << max_count << endl;
}