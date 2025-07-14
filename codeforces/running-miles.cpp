#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> b(n), L(n), R(n);
    for(auto &e:b) cin >> e;
    
    // Finding best (b[l] - (i-l)) for each 'i' greedily
    for (int i = 1; i < n; i++) {
        L[i] = max(L[i-1] - 1, b[i-1] - 1);  // Prefix maximum?
    }
    // Finding best (b[r] - (r-i)) for each 'i' greedily
    for (int i=n-2; i>=0; i--)
        R[i] = max(R[i+1] - 1, b[i+1] - 1);  // Suffix maximum?
    
    // Answer is the maximum L[i] + b[i] + R[i] we can find
    int ans = 0;
    for (int i=1; i<n-1; i++)
        ans = max(ans, L[i] + b[i] + R[i]);
    
    cout << ans << '\n';
}

int main() {
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);
    //ios_base::sync_with_stdio(0);cin.tie(0);
    int t; cin>>t; while(t--)
    solve();
    
    return 0;
}