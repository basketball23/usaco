#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int binSearch(const vector<int>& towers, int target) {
    int low = 0;
    int high = towers.size() - 1;

    while (low <= high) {
        int mid = (high - low)/2 + low;

        if (towers[mid] == target) {
            return towers[mid];
        }

        if (towers[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    if (high < 0) {
        return towers[0];
    }
    if (low >= towers.size()) {
        return towers[towers.size() - 1];
    }

    if (abs(towers[high] - target) > abs(towers[low] - target)) {
        return towers[low];
    } else {
        return towers[high];
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    int minr = 0;

    vector<int> cities(n);
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;

        cities[i] = a;
    }

    vector<int> towers(m);
    for (int i = 0; i < m; i++) {
        int b;
        cin >> b;

        towers[i] = b;
    }

    // Iterate through each of the cities
    // Perform binary search on the list of cell towers, find smallest possible distance
    // Keep a max() of distances
    
    for (int i = 0; i < n; i++) {
        int target = cities[i];

        int closest = abs(binSearch(towers, target) - target);
        minr = max(minr, closest);
    }

    cout << minr << "\n";
}