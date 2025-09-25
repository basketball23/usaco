#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T;
    cin >> T;

    for (int p = 0; p < T; p++) {
        int N;
        cin >> N;

        vector<pair<int, int>> box_intervals(N);

        for (int i = 0; i < N; i++) {
            cin >> box_intervals[i].first >> box_intervals[i].second;
        }

        sort(box_intervals.begin(), box_intervals.end());
        

        priority_queue<int, vector<int>, greater<int>> pq;
        int idx = 0;
        int placed = 0;
        int curr_box = 1;
        bool possible = true;

        while (placed < N) {

            while (idx < N && box_intervals[idx].first <= curr_box) {
                pq.push(box_intervals[idx].second);
                idx++;
            }

            if (pq.empty()) {
                if (idx < N) {
                    curr_box = box_intervals[idx].first;
                    continue;
                } else {
                    possible = false;
                    break;
                }
            }

            int curr = pq.top();
            pq.pop();

            if (curr < curr_box) {
                possible = false;
                break;
            }

            placed++;
            curr_box++;
        }

        if (possible) {
            cout << "Yes" << "\n";
        } else {
            cout << "No" << "\n";
        }

    }
}