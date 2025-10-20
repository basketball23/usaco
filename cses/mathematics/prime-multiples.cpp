#include <iostream>
#include <vector>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, k;
    cin >> n >> k;

    vector<int> primes(k);
    for (int i = 0; i < k; i++) {
        cin >> primes[i];
    }


    // If a number is a multiple of another, the pattern of the on bits must match pattern of the on bits of the divisor?
    // Ex. 110 (6) is divisible by 11 (3)
    // Ex. 10101 (21) is divisible by 101 (7)
    // Ex. 110
}