#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

bool willFinish(int K, const vector<int>& cows, int max_time) {
    vector<int> stage(K);
    int current_time = 0;


    for (int i = 0; i < K; i++) {
        stage[i] = cows[i];
    }

    
    int cow_idx = K;
    while (cow_idx < cows.size()) {
        for (int i = 0; i < K; i++) {
            if (stage[i] == 0) {
                stage[i] = cows[cow_idx];
                cow_idx++;
            }
        }

        for (int i = 0; i < K; i++) {
            stage[i]--;
        }
        current_time++;
    }

    
    int time_remainder = 0;
    for (int i = 0; i < K; i++) {
        time_remainder = max(time_remainder, stage[i]);
    }

    current_time += time_remainder;


    if (current_time > max_time) {
        return false;
    } else {
        return true;
    }
}

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


    int K;

    int low = 0;
    int high = cows.size();

    while (low < high) {
        int mid = low + (high - low)/2;

        if (willFinish(mid, cows, Tmax)) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }

    K = low;
    fout << K << "\n";
}