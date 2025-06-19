#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main() {
    int T, N;
    cin >> T;

    unordered_map<int, int> cows;
    int x, largest = 0, largestpair = 0, ans = 0;
    
    for (int i = 0 ; i < T; i++) {
        cin >> N;
        for (int j = 0; j < N; j++) {
            cin >> x;
            cows[x]++;
            largest = max(largest, x);
            
            if (cows[x] == 2) {
                ans += 2;
                largestpair = max(largestpair, x);
            }
        }
        if (largest > largestpair) {
            ans++;
        } else {
            ans--;
        }
        cout << ans << endl;
        ans = 0;
        largest = 0;
        largestpair = 0;
        cows.clear();
        
    }
    
}