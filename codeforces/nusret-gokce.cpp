#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // setup
    int n, m;
    cin >> n >> m;

    vector<int> steak_slices;

    // input
    for (int i = 0; i < n; i++) {
        int salt;
        cin >> salt;

        steak_slices.push_back(salt);
    }

    // greedy, iterating forward
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        a = steak_slices[i];
        b = steak_slices[i + 1];

        if (a > b) {
            if (a - b > m) {
                b += (a - b) - m;
            }
        } else {
            if (b - a > m) {
                a += (b - a) - m;
            }
        }
        steak_slices[i] = a;
        steak_slices[i + 1] = b;
    }

    // reverse the vector and begin propagating from the opposite head
    reverse(steak_slices.begin(), steak_slices.end());

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        a = steak_slices[i];
        b = steak_slices[i + 1];

        if (a > b) {
            if (a - b > m) {
                b += (a - b) - m;
            }
        } else {
            if (b - a > m) {
                a += (b - a) - m;
            }
        }
        steak_slices[i] = a;
        steak_slices[i + 1] = b;
    }

    // go back to normal
    reverse(steak_slices.begin(), steak_slices.end());

    // output
    for (int i = 0; i < n; i++) {
        cout << steak_slices[i] << " ";
    }
    cout << endl;

    return 0;
}