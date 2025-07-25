#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> steak_slices;

    for (int i = 0; i < n; i++) {
        int salt;
        cin >> salt;

        steak_slices.push_back(salt);
    }

    for (int i = 0; i < n; i++) {
        cout << steak_slices[i] << " ";
    }
    cout << endl;
    return 0;
}