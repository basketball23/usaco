#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int n, x; cin >> n >> x;

    vector<int> values;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        values.push_back(a);
    }

    unordered_map<int, int> complements;

    for (int i = 0; i < n; i++) {
        if (complements.find(x - values[i]) == complements.end()) {
            complements[values[i]] = i;
        } else {
            cout << i + 1 << " " << complements[x - values[i]] + 1 << endl;
            return 0;
        }
    }

    cout << "IMPOSSIBLE" << "\n";
}