#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ifstream fin("div7.in");
    ofstream fout("div7.out");

    int N;
    fin >> N;

    // inputting IDs
    vector<int> cows;

    for (int i = 0; i < N; i++) {
        int id;
        fin >> id;
        cows.push_back(id);
    }

    // calculate prefix sum vector
    vector<long long> prefixSum(N);
    prefixSum[0] = cows[0];

    for (int i = 1; i < N; i++) {
        prefixSum[i] = prefixSum[i - 1] + cows[i];
    }

    int max_cows;
    // check if the first prefix sum is divisible by 7
    if (prefixSum[0] % 7 == 0) {
        max_cows = 1;
    } else{
        max_cows = 0;
    }

    // check all subsequences
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < i; j++) {
            long long sum = prefixSum[i] - (j > 0 ? prefixSum[j - 1] : 0);
            if (sum % 7 == 0){
                int num_cows = i - j + 1;
                max_cows = max(max_cows, num_cows);
            }
        }
    }

    // output result
    fout << max_cows << endl;
    return 0;
}
