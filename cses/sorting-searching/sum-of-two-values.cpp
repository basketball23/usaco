#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, x;
    cin >> n >> x;

    vector<pair<int, int>> values(n);
    for (int i = 0; i < n; i++) {
        cin >> values[i].first;
        values[i].second = i + 1;
    }

    sort(values.begin(), values.end());

    int l = 0, r = n - 1;
    while (l < r) {
        int sum = values[l].first + values[r].first;
        if (sum == x) {
            cout << values[l].second << " " << values[r].second << "\n";
            return 0;
        } else if (sum < x) {
            l++;
        } else {
            r--;
        }
    }

    cout << "IMPOSSIBLE\n";
}