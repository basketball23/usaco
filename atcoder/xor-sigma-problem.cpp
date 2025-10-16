#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> arr(N);

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int total_sum = 0;

    for (int i = 0; i < N - 1; i++) {
        int xor_chain = arr[i];

        for (int j = i + 1; j < N; j++) {
            xor_chain ^= arr[j];

            total_sum += xor_chain;
        }
    }

    cout << total_sum << "\n";
}