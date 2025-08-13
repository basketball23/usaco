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

    // Iterate through each of the cities
    // Perform binary search on the list of cell towers, find smallest possible distance
    // Keep a max() of distances
}