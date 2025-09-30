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
                return a.t > b.t;
            }
        });


        int cut = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        int ptr = 0;

        // Iterate over each restriction
        // Keep a pointer on the trees, and add them to pq while they're less than restriction.r
        // Then, pop from pq (min-heap) while pq.top < restriction.l
        // Then, cut/pop until pq.size() = t.
        // Count how many cut

        for (int i = 1; i < K; i++) {
            Restriction prev_restriction = restrictions[i - 1];
            Restriction curr_restriction = restrictions[i];


            while (ptr < N && trees[ptr] <= curr_restriction.r) {
                pq.push(trees[ptr]);
                ptr++;
            }

            while (pq.top() < prev_restriction.l || pq.size() > prev_restriction.t) {
                pq.pop();
                cut++;
            }
        }

        answers.push_back(cut);
    }
    for (int i = 0; i < T; i++) {
        cout << answers[i] << "\n";
    }
}