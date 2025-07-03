#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector<char> cow_breeds;
vector<vector<int>> road_connections;
vector<int> answers;
bool found = false;

vector<int> dfs(int farm_node, vector<int> path, int target) {
    if (found) {
        return path;
    }
    for (int x : road_connections[farm_node]) {
        if (x == target) {
            found = true;
            return path;
        } else {
            path.push_back(x);
            dfs(x, path, target);
            path.pop_back();
        }
    }
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

    for (int i = 0; i < N; i++) {
        char breed;
        fin >> breed;

        cow_breeds[i] = breed;
    }

    for (int i = 0; i < N - 1; i++) {
        int X, Y;
        fin >> X >> Y;

        road_connections[X].push_back(Y);
        road_connections[Y].push_back(X);
    }
    
    for (int i = 0; i < M; i++) {
        int A, B;
        char C;
        fin >> A >> B >> C;

        vector<int> travel_path;
        found = false;

        vector<int> final_path = dfs(A, travel_path, B);

        bool happy = false;
        for (int n : final_path) {
            if (cow_breeds[n] == C) {
                happy = true;
                break;
            }
        }
        if (happy) {
            answers[i] == 1;
        } else {
            answers[i] == 0;
        }
    }

    // output
    for (int i = 0; i < M; i++) {
        fout << answers[i];
    }
    fout << endl;
}