#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> adjS;
vector<vector<int>> adjD;
vector<int> visited;
int answer = 0;
bool impossible = false;

void dfs(int node, int val) {
    visited[node] = val;
    for (int n : adjS[node]) {
        if (visited[n] == 3 - val) {
            impossible = true;
        }
        if (visited[n] == 0) {
            dfs(n, 3 - val);
        }
    }

    for (int n : adjD[node]) {
        if (visited[n] == val) {
            impossible = true;
        }
        if (visited[n] == 0) {
            dfs(n, 3 - val);
        }
    }
}

int main() {
    ifstream fin("revegetate.in");
    ofstream fout("revegetate.out");

    int N, M;
    fin >> N >> M;

    adjS.resize(N + 1);
    adjD.resize(N + 1);
    visited.resize(N + 1);

    for (int i = 0; i < M; i++) {
        string type;
        int a, b;
        fin >> type >> a >> b;
        if (type == "S") {
            adjS[a].push_back(b); adjS[b].push_back(a);
        } else {
            adjD[a].push_back(b); adjD[b].push_back(a);
        }
    }

    for (int i = 1; i <= N; i++) {
        if (!visited[i]) {
            dfs(i, 1);
            answer++;
        }
    }

    if (impossible) {
        fout << 0 << endl;
        return 0;
    } else {
        fout << "1";
        for (int i = 0; i < answer; i++) {
            fout << "0";
        }
        fout << endl;
        return 0;
    }

}