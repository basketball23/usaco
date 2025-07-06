#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <algorithm>

using namespace std;

vector<int> grazing_times;
map<int, pair<int, int>> grazing_locations;

int valid_alibis = 0;

long long squared(int x) {
    return x * x;
}

int binary_search(int target) {
    int lo = 0;
    int hi = grazing_times.size();

    while (lo < hi) {
        int mid = ((hi - lo)/2) + lo;
        if (grazing_times[mid] <= target) {
            lo = mid + 1;
        } else {
            hi = mid;
        }
    }
    return lo;
}

int main() {
    int G, N, x, y, t;

    cin >> G >> N;

    grazing_times.resize(G, 0);

    for (int i = 0; i < G; i++) {
        cin >> x >> y >> t;

        grazing_times[i] = t;
        grazing_locations[t] = {x, y};
    }

    sort(grazing_times.begin(), grazing_times.end());

    for (int i = 0; i < N; i++) {
        cin >> x >> y >> t;

        int upper = binary_search(t);
        int lower = upper - 1;

        if (lower < 0) {
            if (squared(x - grazing_locations[grazing_times[upper]].first) + squared(y - grazing_locations[grazing_times[upper]].second) > squared(grazing_times[upper] - t)) {
                valid_alibis++;
            }
        } else if (upper > grazing_times.size() - 1) {
            if (squared(x - grazing_locations[grazing_times[lower]].first) + squared(y - grazing_locations[grazing_times[lower]].second) > squared(grazing_times[lower] - t)) {
                valid_alibis++;
            }
        } else {
            if (squared(x - grazing_locations[grazing_times[upper]].first) + squared(y - grazing_locations[grazing_times[upper]].second) > squared(grazing_times[upper] - t) 
            || squared(x - grazing_locations[grazing_times[lower]].first) + squared(y - grazing_locations[grazing_times[lower]].second) > squared(grazing_times[lower] - t)) {
                valid_alibis++;
            }
        }
    }

    cout << valid_alibis << endl;

}
/*
perform binary search on the times of each cow 
compared to the sorted array of each grazing incident
judge if the cow can make it to the grazing of closest time to find the answer
*/