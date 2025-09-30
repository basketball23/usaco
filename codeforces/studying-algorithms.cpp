#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, X;
    cin >> N >> X;

    vector<int> times(N);
    for (int i = 0; i < N; i++) {
        cin >> times[i];
    }
    sort(times.begin(), times.end());

    int count = 0;
    int idx = 0;

    while (idx < N && count + times[idx] <= X) {
        count += times[idx];
        idx++;
    }
    cout << idx << "\n";
}