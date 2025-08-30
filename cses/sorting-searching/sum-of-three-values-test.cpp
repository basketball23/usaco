#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int main() {
    int n, x;
    cin >> n >> x;

    vector<pair<int, int>> nums;

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        nums.push_back({a, i + 1});
    }

    sort(nums.begin(), nums.end());

    bool possible = false;

    for (int i = 2; i < n; i++) {
        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {
            if (right == i) {
                right--;
                continue;
            }
            if (left == i) {
                left++;
                continue;
            }

            if (nums[left].first + nums[right].first + nums[i].first == x) {
                cout << nums[left].second << " " << nums[right].second << " " << nums[i].second << "\n";
                possible = true;
                break;

            } else if (nums[left].first + nums[right].first + nums[i].first > x) {
                right--;
            } else if (nums[left].first + nums[right].first + nums[i].first > x) {
                left++;
            }
        }

        if (possible) {
            break;
        }
    }
    if (!possible) {
        cout << "IMPOSSIBLE" << "\n";
    }
}