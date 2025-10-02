#include <iostream>
#include <vector>

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
    int n;
    cin >> n;

    vector<int> array(n);

    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }

    vector<long long> prefixSum = psum(array);

    /*
    for (int i = 0; i <= n; i++) {
        cout << prefixSum[i] << " ";
    }
    cout << "\n";
    */
    


    long long max_sum = prefixSum[n];

    int left = 0, right = n;

    while (left < right) {
        long long current_sum = prefixSum[right] - prefixSum[left];
        //cout << current_sum << " ";

        if (current_sum > max_sum) {
            max_sum = current_sum;
        }

        if (prefixSum[right] - prefixSum[left + 1] > prefixSum[right - 1] - prefixSum[left]) {
            left++;
        } else {
            right--;
        }
    }

    cout << max_sum << "\n";
}