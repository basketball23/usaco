#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int N, Q;
    string s;
    cin >> N >> Q;
    cin >> s;
    
    long long l, r, val, ans = 0;
    for (int x = 0; x < Q; x++) {
        cin >> l >> r;
        l--;
        r--;
        
        for (int j = l + 1; j < r; j++) {
            int k = r;
            while (s[j] != s[k]) {
                k--;
            }
            if (j == k) {
                continue;
            }
            int i = l;
            while (s[j] == s[i]) {
                i++;
            }
            if (i > j) {
                continue;
            }
            val = ((j + 1) - (i + 1)) * ((k + 1) - (j + 1));
            ans = max(val, ans);
                   
        }
                   
        if (ans == 0) {
            cout << -1 << endl;
        } else {
            cout << ans << endl;
        }
        ans = 0;
        
    }
}