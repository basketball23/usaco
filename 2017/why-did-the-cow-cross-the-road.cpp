#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main() {
    //ifstream cin("helpcross.in");
    //ofstream cout("helpcross.out");

    int C, N;
    cin >> C >> N;

    vector<int> chickens(C);
    vector<bool> visited(C, false);
    for (int i = 0; i < C; i++) {
        cin >> chickens[i];
    }
    sort(chickens.begin(), chickens.end());

    vector<pair<int, int>> cows(N);
    for (int i = 0; i < N; i++) {
        cin >> cows[i].first >> cows[i].second;
    }
    sort(cows.begin(), cows.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        if (a.second != b.second) {
            return a.second < b.second;
        } else {
            return a.first < b.first;
        }
    });


    int total_pairs = 0;
    for (int i = 0, idx = 0; i < N; i++) {
        pair<int, int> curr = cows[i];

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        int lo = 0;
        int hi = C - 1;

        while (lo < hi) {
            int mid = lo + (hi - lo)/2 + 1;
            if (chickens[mid] > curr.second) {
                hi = mid - 1;
            } else {
                lo = mid;
            }
        }

        while (lo >= 0 && chickens[lo] > curr.first) {
            if (visited[lo] == false) {
                pq.push(make_pair(chickens[lo], lo));
            }
            lo--;
        }

        if (!pq.empty()) {
            pair<int, int> top = pq.top();
            visited[top.second] = true;
            total_pairs++;
        }
    }
    
    cout << total_pairs << "\n";
}