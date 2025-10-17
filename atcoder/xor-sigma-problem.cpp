#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (int &a : v) { 
        cin >> a;
    }

    // Accounts for overcounting
	long long ans = -accumulate(v.begin(), v.end(), 0LL);

	for (int i = 0; i < 30; i++) {
        // Calculate bitwise
		int s = 0;
		vector<int> pref = {1, 0};

		for (int a : v) {
            // Extract current bit and xor with running prefix xor
            // Gets you the xors up to this position
			s ^= (a >> i) & 1;

            // Find the number of prefixes up to current position that have a DIFFERING XOR
            // Because subarray has xor 1 if prefix[r] is different from prefix[l - 1]
            // Then multiply by 2^i to get its contribution to the answer
			ans += pref[s ^ 1] * 1LL << i;

            // Add to prefix xor totals
			pref[s]++;
		}
	}

	cout << ans << endl;
}