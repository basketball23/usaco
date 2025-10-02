#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

vector<long long> psum(const vector<int>& nums) {
    /*
    simple function to calculate the prefix sum of a given array
    */

    long long sum = 0;
    vector<long long> prefixSumArray(nums.size() + 1);

    prefixSumArray[0] = 0;

    for (int j = 1; j <= nums.size(); j++) {
        sum += nums[j - 1];
        prefixSumArray[j] = sum;
    }

    return prefixSumArray;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n;
    cin >> n;

    vector<int> array(n);

    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }

    vector<long long> prefixSum = psum(array);


    long long max_sum = prefixSum[n];
    long long min_prefix = prefixSum[0];


    for (int i = 1; i <= n; i++) {
        max_sum = max(max_sum, prefixSum[i] - min_prefix);
        min_prefix = min(min_prefix, prefixSum[i]);
    }

    cout << max_sum << "\n";
}