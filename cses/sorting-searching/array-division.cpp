#include <iostream>
#include <vector>
#include <climits>

using namespace std;

vector<int> nums;

bool canDivide(int max_sum, int k) {
    int subarrays[k];

    for (int i = 0; i < nums.size(); i++) {
        int idx = i % k;

        subarrays[idx] += nums[idx];
    }

    for (int i = 0; i < k; i++) {
        if (subarrays[i] > max_sum) {
            return false;
        }
    }
    return true;
}

int main() {
    int n, k;
    cin >> n >> k;

    nums.resize(n);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        nums[i] = x;
    }

    // find maximum minimum sum of array division
    // function looks like (false, false, false, true, true, true)

    int lo = 0;
    int hi = INT_MAX;

    while (lo < hi) {
        int mid = lo + (hi - lo)/2;

        if (canDivide(mid, k)) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }

    cout << lo << "\n";
}