#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    long long n;
    int k;
    cin >> n >> k;

    vector<long long> primes(k);
    for (int i = 0; i < k; i++) {
        cin >> primes[i];
    }

    long long ans = 0;

    // First pass
    for (int i = 0; i < k; i++) {
        long long multiples = n / primes[i];
        ans += multiples;
    }

    // Second pass to get rid of duplicates
    for (int i = 0; i < k; i++) {
        long long duplicates = 0;
        for (int j = i + 1; j < k; j++) {
            duplicates += n / (primes[i] * primes[j]);
        }
        ans -= duplicates;
    }

    cout << ans << "\n";

    // If a number is a multiple of another, the pattern of the on bits must match pattern of the on bits of the divisor?
    // Ex. 110 (6) is divisible by 11 (3)
    // Ex. 10101 (21) is divisible by 101 (7)
    // Ex. 110
}