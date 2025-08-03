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

    int single_enc_area = (xmax - xmin) * (ymax - ymin);
    int double_enc_area = 2147483647;

    // ALGORITHM:
    /*
    Sort points by x coordinate, and check bounding boxes by partitioning at each x-coordinate
    */

    sort(cows.begin(), cows.end());

    //create list of min and max y at each x-coordinate

    vector<pair<int, int>> limit_list_left;
    ymax = 0, ymin = 1000000000;
    for (int i = 0; i < N; i++) {
        ymax = max(cows[i].second, ymax); ymin = min(cows[i].second, ymin);
        limit_list_left.push_back({ymin, ymax});
    }

    vector<pair<int, int>> limit_list_right;
    ymax = 0, ymin = 1000000000;
    for (int i = N - 1; i >= 0; i--) {
        ymax = max(cows[i].second, ymax); ymin = min(cows[i].second, ymin);
        limit_list_right.push_back({ymin, ymax});
    }

    reverse(limit_list_right.begin(), limit_list_right.end());

    int left_l = cows[0].first, left_r, right_l, right_r = cows[N - 1].first;

    for (int i = 0; i < N - 1; i++) {

        if (cows[i].first == cows[i + 1].first) {
            // skip processing x val if duplicates
            continue;
        }

        left_r = cows[i].first;
        right_l = cows[i + 1].first;

        int left_area = (left_r - left_l) * (limit_list_left[i].second - limit_list_left[i].first);
        int right_area = (right_r - right_l) * (limit_list_right[i + 1].second - limit_list_right[i + 1].first);

        int current_area = left_area + right_area;

        double_enc_area = min(double_enc_area, current_area);
    }

    fout << (single_enc_area - double_enc_area) << "\n";

}