#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main() {
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

    vector<pair<int, int>> grassy_patches;

    for (int i = 0; i < K; i++) {
        int p, t;
        cin >> p >> t;

        grassy_patches.push_back({p, t});
    }

    sort(grassy_patches.begin(), grassy_patches.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second;
    });


    vector<int> nhoj_cows;
    for (int i = 0; i < M; i++) {
        int f;
        cin >> f;

        nhoj_cows.push_back(f);
    }

    
}