#include <iostream>
#include <vector>

using namespace std;

vector<int> nums;

bool canDivide(int max_sum) {

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
    int hi = nums.size() - 1;

    while (lo < hi) {
        int mid = lo + (hi - lo)/2;

        if (canDivide(mid)) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }

    cout << lo << "\n";
}