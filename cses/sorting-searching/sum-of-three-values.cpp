#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, x;
    cin >> n >> x;

    vector<int> nums;

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        nums.push_back(a);
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

            if (nums[left] + nums[right] + nums[i] == x) {
                cout << left << " " << right << " " << i << "\n";
                possible = true;
                break;

            } else if (nums[left] + nums[right] + nums[i] > x) {
                right--;
            } else if (nums[left] + nums[right] + nums[i] < x) {
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