#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <algorithm>
#include <cmath>

using namespace std;

vector<int> grazing_times;
map<int, pair<int, int>> grazing_locations;

int valid_alibis = 0;

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

    for (int i = 0; i < G; i++) {
        cin >> x >> y >> t;

        grazing_times.push_back(t);
        grazing_locations[t] = {x, y};
    }

    sort(grazing_times.begin(), grazing_times.end());

    for (int i = 0; i < N; i++) {
        cin >> x >> y >> t;

        int travel_time;
        int idx = binary_search(t);

        if ((t - grazing_times[idx - 1]) < grazing_times[idx] - t) {
            idx--;
            travel_time = (t - grazing_times[idx - 1]);
        } else {
            travel_time = grazing_times[idx] - t;
        }

        if (pow(x - grazing_locations[grazing_times[idx]].first, 2) + pow(y - grazing_locations[grazing_times[idx]].second, 2) >= pow(travel_time, 2)) {
            valid_alibis++;
        }
    }

    cout << valid_alibis << endl;

}
/*
perform binary search on the times of each cow 
compared to the sorted array of each grazing incident
judge if the cow can make it to the grazing of closest time to find the answer
*/