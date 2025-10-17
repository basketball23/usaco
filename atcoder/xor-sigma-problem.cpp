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

	long long ans = -accumulate(v.begin(), v.end(), 0LL);

	for (int i = 0; i < 30; i++) {
		int s = 0;
		vector<int> pref = {1, 0};

		for (int a : v) {
			s ^= (a >> i) & 1;

			ans += pref[s ^ 1] * 1LL << i;

			pref[s]++;
		}
	}

	cout << ans << endl;
}