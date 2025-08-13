#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ifstream fin("haybales.in");
    ofstream fout("haybales.out");

    int N, Q;
    fin >> N >> Q;

    vector<int> haybales(N);
    for (int i = 0; i < N; i++) {
        int h; fin >> h;
        haybales[i] = h;
    }

    sort(haybales.begin(), haybales.end());

    for (int i = 0; i < Q; i++) {
        int A, B;
        fin >> A >> B;

        int low = 0;
        int high = haybales.size();
        int mid;

        while (low < high) {
            mid = (high + low)/2;

            if (haybales[mid] <= A) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }

        int low_idx = low - 1;

        low = 0;
        high = haybales.size();
        mid;

        while (low < high) {
            mid = (high + low)/2;

            if (haybales[mid] <= B) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }

        int high_idx = low;

        fout << high_idx - low_idx << "\n";
    }
}