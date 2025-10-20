#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int distance(int x1, int y1, int x2, int y2) {
    return (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N;
    cin >> N;
    

    vector<int> xval(N), yval(N);

    for (int i = 0; i < N; i++) {
        cin >> xval[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> yval[i];
    }


    int max_dist = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            int dist = distance(xval[i], yval[i], xval[j], yval[j]);
            
            if (dist > max_dist) {
                max_dist = dist;
            }
        }
    }

    cout << max_dist << "\n";
}