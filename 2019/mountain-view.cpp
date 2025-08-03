#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ifstream fin("mountains.in");
    ofstream fout("mountains.out");

    int N; fin >> N;

    vector<pair<int, int>> peaks;
    vector<pair<int, int>> distinct;

    for (int i = 0; i < N; i++) {
        int x, y; fin >> x >> y;
        peaks.push_back({x, y});
    }

    sort(peaks.begin(), peaks.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second < b.second;
    });

    reverse(peaks.begin(), peaks.end());

    distinct.push_back(peaks[0]);
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < distinct.size(); j++) {
            int x1 = peaks[1].first, y1 = peaks[i].second, x2 = distinct[j].first, y2 = distinct[j].second;
            int xdiff = x2 - x1, ydiff = y2 - y1;
            if (abs(xdiff) > ydiff) {
                
            }
        }
    }

    // sort by y values
    // iterate through, and for each coordinate you can calculate if it exists in another by comparing y values, taking the difference and applying to x vals
    // have a separate vector for holding distinct peaks. only compare current peak to these distinct peaks.
}