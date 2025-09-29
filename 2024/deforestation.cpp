#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

struct Restriction {
    int l;
    int r;
    int t;
};

int main() {
    cin.tie(nullptr) -> sync_with_stdio(false);

    int T;
    cin >> T;

    vector<int> answers;

    for (int p = 0; p < T; p++) {
        int N, K;
        cin >> N >> K;


        vector<int> trees(N);
        for (int i = 0; i < N; i++) {
            cin >> trees[i];
        }
        sort(trees.begin(), trees.end());


        vector<Restriction> restrictions(K);
        for (int i = 0; i < K; i++) {
            cin >> restrictions[i].l >> restrictions[i].r >> restrictions[i].t;
        }
        sort(restrictions.begin(), restrictions.end(), [](const Restriction& a, const Restriction& b){
            if (a.r != b.r) {
                return a.r < b.r;
            } else {
                return a.l < b.l;
            }
        });


        set<int> kept;

        for (int i = 0; i < K; i++) {
            priority_queue<int> pq;
            Restriction curr_restriction = restrictions[i];

            // Binary search to find trees less than curr_restriction.r

            int lo = 0;
            int hi = N - 1;

            while (lo < hi) {
                int mid = lo + (hi - lo)/2 + 1;
                if (trees[mid] > curr_restriction.r) {
                    hi = mid - 1;
                } else {
                    lo = mid;
                }
            }

            while (lo >= 0 && trees[lo] >= curr_restriction.l) {
                if (kept.find(trees[lo]) != kept.end()) {
                    curr_restriction.t--;
                } else {
                    pq.push(trees[lo]);
                }
                lo--;
            }

            while (curr_restriction.t > 0) {
                int rightmost = pq.top();
                pq.pop();
                kept.insert(rightmost);
                curr_restriction.t--;
            }
        }

        answers.push_back(N - kept.size());
    }
    for (int i = 0; i < T; i++) {
        cout << answers[i] << "\n";
    }
}