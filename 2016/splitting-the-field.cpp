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

    long long single_enc_area = (xmax - xmin) * (ymax - ymin);
    long long double_enc_area = 2147483647;

    // ALGORITHM:
    /*
    Sort points by x coordinate, and check bounding boxes by partitioning at each x-coordinate
    */

    sort(cows.begin(), cows.end());

    //create list of min and max y at each x-coordinate

    vector<int> limit_list_left;
    ymax = 0, ymin = 1000000000;
    for (int i = 0; i < N; i++) {
        ymax = max(cows[i].second, ymax); ymin = min(cows[i].second, ymin);
        limit_list_left.push_back(ymax - ymin);
    }

    vector<int> limit_list_right;
    ymax = 0, ymin = 1000000000;
    for (int i = N - 1; i >= 0; i--) {
        ymax = max(cows[i].second, ymax); ymin = min(cows[i].second, ymin);
        limit_list_right.push_back(ymax - ymin);
    }

    reverse(limit_list_right.begin(), limit_list_right.end());

    int left_l = cows[0].first, left_r, right_l, right_r = cows[N - 1].first;

    // Vertical loop
    for (int i = 0; i < N - 1; i++) {

        if (cows[i].first == cows[i + 1].first) {
            // skip processing x val if duplicates
            continue;
        }

        left_r = cows[i].first;
        right_l = cows[i + 1].first;

        long long left_area = (left_r - left_l) * (limit_list_left[i]);
        long long right_area = (right_r - right_l) * (limit_list_right[i + 1]);

        long long current_area = left_area + right_area;

        double_enc_area = min(double_enc_area, current_area);
    }

    // TODO: run a horizontal loop

    sort(cows.begin(), cows.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second < b.second;
    });


    //create list of min and max x at each y-coordinate

    vector<int> limit_list_bottom;
    xmax = 0, xmin = 1000000000;
    for (int i = 0; i < N; i++) {
        xmax = max(cows[i].first, xmax); xmin = min(cows[i].first, xmin);
        limit_list_bottom.push_back(xmax - xmin);
    }

    vector<int> limit_list_top;
    xmax = 0, xmin = 1000000000;
    for (int i = N - 1; i >= 0; i--) {
        xmax = max(cows[i].first, xmax); xmin = min(cows[i].first, xmin);
        limit_list_top.push_back(xmax - xmin);
    }

    reverse(limit_list_top.begin(), limit_list_top.end());

    int bottom_b = cows[0].second, bottom_t, top_b, top_t = cows[N - 1].second;

    for (int i = 0; i < N - 1; i++) {
        if (cows[i].second == cows[i + 1].second) {
            // skip processing y val if duplicates
            continue;
        }
        bottom_t = cows[i].second;
        top_b = cows[i + 1].second;

        long long bottom_area = (bottom_t - bottom_b) * (limit_list_bottom[i]);
        long long top_area = (top_t - top_b) * (limit_list_top[i + 1]);

        long long current_area = bottom_area + top_area;

        double_enc_area = min(double_enc_area, current_area);

    }

    fout << (single_enc_area - double_enc_area) << "\n";

}