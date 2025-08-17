#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    ifstream fin("cowdance.in");
    ofstream fout("cowdance.out");

    int N, Tmax;
    fin >> N >> Tmax;

    vector<int> cows;

    for (int i = 0; i < N; i++) {
        int d;
        fin >> d;

        cows.push_back(d);
    }

    // binary search for values of K that will make the show finish in time

    // Given that if K = N, show will finish in time
    // So list of all K's will look like:
    // false false false false false false true true true true

    // Our job is to find the minimum true
    // Checking if K works can be represented as a function, looping through the cows (O[n])
}