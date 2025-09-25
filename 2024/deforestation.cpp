#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

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

        int total_cut = 0;
        int idx = 0;
        
        while (idx < N) {
            /*
            ALGORITHM:
            iterate through each tree, and basically ASSIGN the tree to all avaliable restricitons
            fill the restrictions until the minimum is satisfied

            if there are no restrictions to fill when we have a tree, then increment a count (of trees able to cut down)
            */
        }

        cout << total_cut << "\n";
    }
}