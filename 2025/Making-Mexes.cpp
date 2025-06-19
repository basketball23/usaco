#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int N, x, ans = 0;
    cin >> N;
    vector<int> arr;
    
    for (int i = 0; i < N; i++) {
        cin >> x;
        arr.push_back(x);
    }
    sort(arr.begin(), arr.end());
    int repeated = 0;
    
    for (int i = 0; i <= N; i++) {
        
        for (int j = 0; j < i; j++) {
            if (binary_search(arr.begin(), arr.end(), j) == false) {
                ans++;
            }
        }
        repeated = count(arr.begin(), arr.end(), i);
        repeated -= ans;
        if (repeated > 0) {
            ans += repeated;
        }
        
        cout << ans << endl;
        ans = 0;
        repeated = 0;
    }
    
    
}