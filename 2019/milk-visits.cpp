#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector<char> cow_breeds;
vector<vector<int>> road_connections;
vector<int> answers;
vector<bool> visited;
vector<int> path;
bool found = false;

void dfs(int farm, int target) {
    /*
    dfs function
    */
    if (found) {
        return;
    }

    visited[farm] = true;
    path.push_back(farm);

    if (farm == target) {
        found = true;
        return;
    }

    for (int x : road_connections[farm]) {
        if (!visited[x]) {
            dfs(x, target);
            if (found) {
                return;
            }
        }
    }

    path.pop_back();
}

int main() {
    ifstream fin("milkvisits.in");
    ofstream fout("milkvisits.out");

    int N, M;

    fin >> N >> M;

    // resizing
    cow_breeds.resize(N);
    road_connections.resize(N);
    answers.resize(M, 0);
    visited.resize(N, false);

    // inputting
    for (int i = 0; i < N; i++) {
        fin >> cow_breeds[i];
    }

    for (int i = 0; i < N - 1; i++) {
        int X, Y;
        fin >> X >> Y;

        X--; Y--;

        road_connections[X].push_back(Y);
        road_connections[Y].push_back(X);
    }


    // main logic
    for (int i = 0; i < M; i++) {
        int A, B;
        char C;
        fin >> A >> B >> C;

        A--; B--;

        path.clear();
        found = false;
        fill(visited.begin(), visited.end(), false);

        dfs(A, B);

        for (int node : path) {
            if (cow_breeds[node] == C) {
                answers[i] = 1;
                break;
            }
        }
    }

    // output
    for (int i = 0; i < M; i++) {
        fout << answers[i];
    }
    fout << endl;
}