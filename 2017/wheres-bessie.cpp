#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<vector<char>> grid;
vector<vector<char>> current_PCL;
vector<vector<int>> coordinates_PCL;
/*
SAVE PCLS AS 4 COORDINATES MAKING THE RECTANGLE
THIS ALLOWS FOR CHECKING IF A PCL IS A SUBPCL, WHICH DOESN'T COUNT 
*/

void flood(int r, int c) {
    if (r >= N || c >= N || /* add check for exceeding 2 characters*/) {
        return;
    }

    flood(r + 1, c);
    flood(r, c + 1);


}

int main() {
    ifstream fin("where.in");
    ofstream fout("where.out");

    fin >> N;

    grid.resize(N, vector<char>(N));

    for (int i = 0; i < N; i++) {
        for (int j = 0; i < N; j++) {
            char c;
            fin >> c;
            grid[i][j] = c;
        }
    }

}