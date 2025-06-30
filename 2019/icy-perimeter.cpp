#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int N, current_area = 0, current_perimeter = 0, max_area = 0, perimeter = 0;
vector<vector<char>> grid;
vector<vector<bool>> visited;

void flood(int r, int c) {
    if (r < 0 || r >= N || c < 0 || c >= N || grid[r][c] == '.' || visited[r][c] == true) {
        return;
    }

    visited[r][c] = true;

    current_area++;
    if (r == 0 || grid[r - 1][c] == '.') current_perimeter++;
    if (r == N - 1 || grid[r + 1][c] == '.') current_perimeter++;
    if (c == 0 || grid[r][c - 1] == '.') current_perimeter++;
    if (c == N - 1 || grid[r][c + 1] == '.') current_perimeter++;

    flood(r + 1, c);
    flood(r - 1, c);
    flood(r, c + 1);
    flood(r, c - 1);
}

int main() {
    ifstream fin("perimeter.in");
    ofstream fout("perimeter.out");

    fin >> N;

    grid.resize(N, vector<char>(N));
    visited.resize(N, vector<bool>(N, false));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            char c;
            fin >> c;
            grid[i][j] = c;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (grid[i][j] == '#' && !visited[i][j]) {
                current_area = 0; current_perimeter = 0;
                flood(i, j);
                if (current_area > max_area) {
                    max_area = current_area;
                    perimeter = current_perimeter;
                }
                if (current_area == max_area) {
                    perimeter = min(perimeter, current_perimeter);
                }
            }
        }
    }

    fout << max_area << " " << perimeter << endl;
    return 0;
}