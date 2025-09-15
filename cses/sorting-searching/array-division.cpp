#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

vector<int> nums;

bool canDivide(long long max_sum, int k) {
    int num_arr = 1;
    long long curr_sum = 0;


    for (int idx = 0; idx < (int)nums.size(); idx++) {
        if (curr_sum + nums[idx] > max_sum) {
            num_arr++;
            curr_sum = nums[idx];

            if (num_arr > k) {
                return false;
            }
        } else {
            curr_sum += nums[idx];
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

    long long lo = *max_element(nums.begin(), nums.end());
    long long hi = accumulate(nums.begin(), nums.end(), 0LL);

    while (lo < hi) {
        long long mid = lo + (hi - lo)/2;

        if (canDivide(mid, k)) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }

    cout << lo << "\n";
}