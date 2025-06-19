#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>

using namespace std;

int main() {
    freopen("diamond.in", "r", stdin);
    freopen("diamond.out", "w", stdout);
    
    int n, k;
    cin >> n >> k;
    
    vector<int> nums;
    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        nums.push_back(x);
    }
    
    sort(nums.begin(), nums.end());
    
    int left = 0, ans = 0;
    
    for (int right = 1; right < n; right++) {
        while (nums[right] - nums[left] > k) {
            left++;
        }
        ans = max(right - left + 1, ans);
    }
    

    cout << ans;
}    
