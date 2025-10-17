#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
    string S;
    cin >> S;
    int n = S.size();

    // frequency of prefix parity states (stores counts)
    unordered_map<int, long long> freq;
    freq[0] = 1;  // empty prefix has even counts of all digits

    // uses a bitmask to keep track of occurence parity
    int mask = 0;
    long long ans = 0;

    for (char c : S) {
        int digit = c - '0';
        mask ^= (1 << digit);  // flip bit for that digit

        // count how many previous prefixes had same mask
        ans += freq[mask];

        freq[mask]++;
    }

    
    cout << ans << "\n";
}
