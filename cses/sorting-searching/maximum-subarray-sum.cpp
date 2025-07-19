#include <iostream>
#include <vector>
#include <limits>
using namespace std;

vector<int> psum(vector<int> nums) {
    /*
    simple function to calculate the prefix sum of a given array
    */

    int sum = 0;
    vector<int> prefixSumArray(nums.size());

    for (int j = 0; j < nums.size(); j++) {
        sum += nums[j];
        prefixSumArray[j] = sum;
    }

    return prefixSumArray;
}

int main() {
    int n, max_sum = numeric_limits<int>::min();
    cin >> n;

    vector<int> array;

    array.assign(n, 0);

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        array[i] = x;
    }

    int left = 0, right = array.size() - 1;

    while (left <= right) {
        int current_sum = 0;
        for (int i = left; i <= right; i++) {
            current_sum += array[i];
        }
        if (current_sum > max_sum) {
            max_sum = current_sum;
        }

        if (array[left] > array[right]) {
            right--;
        } else {
            left++;
        }
    }

    cout << max_sum;

}