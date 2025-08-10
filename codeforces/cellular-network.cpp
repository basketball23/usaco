#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> cities(n);
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;

        cities[i] = a;
    }

    vector<int> towers(m);
    for (int i = 0; i < m; i++) {
        int b;
        cin >> b;

        towers[i] = b;
    }

    // iterate through cell tower positions, and binary search the value on the city array
    // find smallest value that it will cover the first city
    // then, find smallest value for the next tower that will cover the leftmost city that hasn't been covered already
}