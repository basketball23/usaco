#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int K, M, N;
    cin >> K >> M >> N;

    // Algorithm:
    /*
    Iterate through each grassy patch (by order or tastiness or position?)

    Determine the closest farmer Nhoj's cow using binary search

    Test the farthest farmer John's cow can be while still winning it, to see if we can win more
    Mark all won patches in a separate vector

    Add total 
    */

    vector<vector<int>> patches_bysize;
    vector<pair<int, int>> grassy_patches;
    vector<bool> patches_won(K, false);

    for (int i = 0; i < K; i++) {
        int p, t;
        cin >> p >> t;

        patches_bysize.push_back({p, t, i});
        grassy_patches.push_back({p, t});
    }

    sort(patches_bysize.begin(), patches_bysize.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[1] > b[1];
    });


    vector<int> nhoj_cows;
    for (int i = 0; i < M; i++) {
        int f;
        cin >> f;

        nhoj_cows.push_back(f);
    }

    sort(nhoj_cows.begin(), nhoj_cows.end());
    // Main logic

    for (int i = 0; i < K; i++) {
        if (!patches_won[i]) {

        }
    }

    // Counting ouput

    long long total = 0;

    for (int i = 0; i < K; i++) {
        if (patches_won[i] == true) {
            total += grassy_patches[i].second;
        }
    }

    cout << total << "\n";
}