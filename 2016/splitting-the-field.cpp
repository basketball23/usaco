#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main() {
    ifstream fin("split.in");
    ofstream fout("split.out");

    int N; fin >> N;
    int xmax = 0, xmin = 1000000000, ymax = 0, ymin = 1000000000;
    
    vector<pair<int, int>> cows;

    for (int i = 0; i < N; i++) {
        int x, y; fin >> x >> y;
        xmax = max(x, xmax); xmin = min(x, xmin); ymax = max(y, ymax); ymin = min(y, ymin);
        cows.push_back({x, y});
    }

    int single_enc = (xmax - xmin) * (ymax - ymin);
    int double_enc;

    //main logic goes here

    fout << (single_enc - double_enc) << "/n";

}