#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cassert>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int K, M, N;
    cin >> K >> M >> N;

    vector<pair<int, int>> patches(K + M);
    for (int i = 0; i < K; i++) {
        cin >> patches[i].first >> patches[i].second;
    }

    for (int i = K; i < K + M; i++) {
        cin >> patches[i].first;
        patches[i].second = -1;
    }

    sort(patches.begin(), patches.end());

    vector<unsigned long long> increases;
    int last_i = -1;

    unsigned long long sum_range = 0;

    for (int i = 0; i < (int)patches.size(); ++i) {
        if (patches[i].second == -1) {
            if (last_i == -1) {
                increases.push_back(sum_range);
            } else {
                unsigned long long cur_ans_1 = 0;
                unsigned long long best_ans_1 = 0;
                for (int j = last_i + 1, r = last_i; j < i; ++j) {
                    while (r + 1 < i &&
                        (patches[r + 1].first - patches[j].first) * 2 <
                            patches[i].first - patches[last_i].first) {
                        
                        cur_ans_1 += patches[++r].second;
                    }

                    best_ans_1 = max(best_ans_1, cur_ans_1);
                    cur_ans_1 -= patches[j].second;
                }
                assert(2 * best_ans_1 >= sum_range);

                increases.push_back(best_ans_1);
                increases.push_back(sum_range - best_ans_1);
            }
            last_i = i;
            sum_range = 0;
        } else {
            sum_range += patches[i].second;
        }
    }

    increases.push_back(sum_range);

    sort(increases.begin(), increases.end(), [](const unsigned long long& a, const unsigned long long& b) {
        return a > b;
    });
    increases.resize(N);
    unsigned long long ans = 0;
    for (auto val : increases) {
        ans += val;
    }
    cout << ans << "\n";
}