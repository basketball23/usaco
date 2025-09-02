#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

// Partial solution
int main() {
    int n;
    cin >> n;

    long long current_time = 0;
    long long max_reward = 0;

    vector<pair<int, int>> tasks;

    for (int i = 0; i < n; i++) {
        int a, d;
        cin >> a >> d;
        tasks.push_back({a, d});
    }

    sort(tasks.begin(), tasks.end());

    for (int i = 0; i < n; i++) {
        current_time += tasks[i].first;
        max_reward += tasks[i].second - current_time;
    }

    cout << max_reward << "\n";
}