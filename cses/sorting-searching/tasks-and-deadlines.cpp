#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

// Partial solution
int main() {
    int n;
    cin >> n;

    int current_time = 0;
    int max_reward = 0;

    vector<pair<int, int>> tasks;

    for (int i = 0; i < n; i++) {
        int a, d;
        cin >> a >> d;
        tasks.push_back({a, d});
    }

    sort(tasks.begin(), tasks.end());

    for (int i = 0; i < n; i++) {
        current_time += tasks[i].first;

        int reward = tasks[i].second - current_time;
        max_reward += reward;
    }

    cout << max_reward << "\n";
}