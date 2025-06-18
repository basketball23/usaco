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
        for (int i = l; i < r - 1; i++) {
            for (int j = i + 1; j < r; j++) {
                for (int k = j + 1; k <= r; k++) {
                    if (s[j] == s[k] && s[j] != s[i]) {
                        val = ((j + 1) - (i + 1)) * ((k + 1) - (j + 1));
                        ans = max(val, ans);
                    }
                }
            }
        }
        if (ans == 0) {
            cout << -1 << endl;
        } else {
            cout << ans << endl;
        }
        ans = 0;
        
    }
}