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
    for (int i = 0; i < N; i++) {
        int x, y; fin >> x >> y;
        peaks.push_back({x, y});
    }

    sort(peaks.begin(), peaks.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second < b.second;
    });

    reverse(peaks.begin(), peaks.end());

    

    // sort by y values
    // iterate through, and for each coordinate you can calculate if it exists in another by comparing y values, taking the difference and applying to x vals
    // have a separate vector for holding distinct peaks. only compare current peak to these distinct peaks.
}