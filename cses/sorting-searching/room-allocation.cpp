#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n;
    cin >> n;

    vector<int> ans(n);
    vector<pair<pair<int, int>, int>> customers(n);

    for (int i = 0; i < n; i++) {
        cin >> customers[i].first.first >> customers[i].first.second;
        customers[i].second = i;
    }
    sort(customers.begin(), customers.end());

    int last_room = 0;
    using Room = pair<int, int>;
    priority_queue<Room, vector<Room>, greater<Room>> pq;

    for (int i = 0; i < n; i++) {
        if (pq.empty() || pq.top().first >= customers[i].first.first) {
            last_room++;

            pq.push(make_pair(customers[i].first.second, last_room));

            ans[customers[i].second] = last_room;
        } else {
            Room top_element = pq.top();
            pq.pop();
            pq.push(make_pair(customers[i].first.second, top_element.second));

            ans[customers[i].second] = top_element.second;
        }
    }

    cout << last_room << "\n";
    for (int i = 0; i < n; i++) {
        if (i != n - 1) {
            cout << ans[i] << " ";
        } else {
            cout << ans[i] << "\n";
        }
    }
}