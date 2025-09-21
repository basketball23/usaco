#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main() {
    ifstream fin("convention2.in");
    ofstream fout("convention2.out");

    int N;
    fin >> N;

    vector<pair<pair<int, int>, int>> cows(N);

    for (int i = 0; i < N; i++) {
        fin >> cows[i].first.first >> cows[i].second;

        cows[i].first.second = i;
    }
    sort(cows.begin(), cows.end());

    int max_waited = 0;
    int time = 0;
    using info = pair<pair<int, int>, int>;
    priority_queue<info> pq;

    for (int i = 0; i < N; i++) {
        if (pq.empty()) {
            if (time < cows[i].first.first) {
                time = cows[i].first.first + cows[i].second;
            } else {
                pq.push(make_pair(make_pair(cows[i].first.second, cows[i].second), cows[i].first.first));
            }
        } else {
            if (cows[i].first.first >= time) {

                if (cows[i].first.first == time) {
                    pq.push(make_pair(make_pair(cows[i].first.second, cows[i].second), cows[i].first.first));
                }

                info priority_cow = pq.top();
                pq.pop();

                int time_waited = time - priority_cow.second;
                max_waited = max(max_waited, time_waited);

                time += priority_cow.first.second;
            } else {
                pq.push(make_pair(make_pair(cows[i].first.second, cows[i].second), cows[i].first.first));
            }
        }
    }

    while (!pq.empty()) {
        info priority_cow = pq.top();
        pq.pop();

        int time_waited = time - priority_cow.second;
        max_waited = max(max_waited, time_waited);

        time += priority_cow.first.second;
    }

    fout << max_waited << "\n";
}