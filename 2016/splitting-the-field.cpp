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

    // ALGORITHM:
    /*
    Sort points by x coordinate, and check bounding boxes by partitioning at each x-coordinate
    */


    // keep a running pair of minimum y
    sort(cows.begin(), cows.end());

    int left_l = cows[0].first, left_r, right_l, right_r = cows[N - 1].first;

    for (int i = 0; i < N - 1; i++) {
        if (i != N - 2) {
            if (cows[i].first == cows[i + 1].first) {
                // skip processing x val if duplicates
                continue;
            }
        }

        left_r = cows[i].first;
        right_l = cows[i + 1].first;



    }

    fout << (single_enc - double_enc) << "/n";

}