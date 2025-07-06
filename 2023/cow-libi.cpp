#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct GrazingEvent {
    int t;
    int x;
    int y;

    bool operator<(const GrazingEvent& other) const {
        return t < other.t;
    }
};

vector<GrazingEvent> grazings;

int valid_alibis = 0;

long long squared(int x) {
    return (long long)x * x;
}

int binary_search_grazing_events(int target) {
    int lo = 0;
    int hi = grazings.size();

    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (grazings[mid].t <= target) {
            lo = mid + 1;
        } else {
            hi = mid;
        }
    }
    return lo;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int G, N;
    cin >> G >> N;

    grazings.resize(G);

    for (int i = 0; i < G; i++) {
        cin >> grazings[i].x >> grazings[i].y >> grazings[i].t;
    }

    sort(grazings.begin(), grazings.end());

    for (int i = 0; i < N; i++) {
        int cow_x, cow_y, cow_t;
        cin >> cow_x >> cow_y >> cow_t;

        int upper_idx = binary_search_grazing_events(cow_t);
        int lower_idx = upper_idx - 1;

        bool is_innocent = false;

        if (upper_idx < grazings.size()) {
            const GrazingEvent& g_upper = grazings[upper_idx];
            long long dist_sq = squared(cow_x - g_upper.x) + squared(cow_y - g_upper.y);
            long long time_diff_sq = squared(g_upper.t - cow_t);

            if (dist_sq > time_diff_sq) {
                is_innocent = true;
            }
        }

        if (!is_innocent && lower_idx >= 0) {
            const GrazingEvent& g_lower = grazings[lower_idx];
            long long dist_sq = squared(cow_x - g_lower.x) + squared(cow_y - g_lower.y);
            long long time_diff_sq = squared(g_lower.t - cow_t);

            if (dist_sq > time_diff_sq) {
                is_innocent = true;
            }
        }
        
        if (is_innocent) {
            valid_alibis++;
        }
    }

    cout << valid_alibis << endl;

    return 0;
}
