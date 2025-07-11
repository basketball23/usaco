#include <iostream>
#include <vector>

using namespace std;

vector<int> sight_beauties;

int main() {
    int testcases;
    cin >> testcases;

    for (int i = 0; i < testcases; i++) {
        int n;
        cin >> n;

        sight_beauties.assign(n, 0);

        for (int j = 0; j < n; j++) {
            int x;
            cin >> sight_beauties[j];
        }

        

    }
}