#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <utility>
#include <cmath>

using namespace std;

// Check if detonating with a R value works or not

// Drop the cow at the largest difference between locations in hay bales
bool detonationPossible(int R, const vector<int>& hay_bales, int drop_idx) {

    int drop_middle = (hay_bales[drop_idx] + hay_bales[drop_idx + 1])/2;
    bool still_detonating = true;

    // Iterate left
    int curr_R = R;
    int curr_idx = drop_idx;
    int detonation_center = drop_middle;

    while (still_detonating) {

        if (hay_bales[curr_idx] < detonation_center - curr_R) {
            still_detonating = false;
            break;
        }

        while (hay_bales[curr_idx] >= detonation_center - curr_R) {
            curr_idx--;
            if (curr_idx == -1) {
                break;
            }
        }

        detonation_center = hay_bales[curr_idx + 1];
        curr_R--;
    }

    if (!still_detonating) {
        return false;
    }
    
    // Iterate right
    curr_R = R;
    curr_idx = drop_idx + 1;
    detonation_center = drop_middle;

    while (still_detonating) {

        if (hay_bales[curr_idx] > detonation_center + curr_R) {
            still_detonating = false;
            break;
        }

        while (hay_bales[curr_idx] <= detonation_center + curr_R) {
            curr_idx++;
            if (curr_idx == hay_bales.size()) {
                break;
            }
        }

        detonation_center = hay_bales[curr_idx - 1];
        curr_R--;
    }

    if (!still_detonating) {
        return false;
    }

    return true;
}

// Function returns the index of largest gap in hay bales (lower bound)
int largest_diff(const vector<int>& hay_bales) {
    int largest_gap_idx;
    int difference = 0;

    for (int j = 0; j < hay_bales.size() - 1; j++) {
        if (hay_bales[j + 1] - hay_bales[j] > difference) {
            difference = hay_bales[j + 1] - hay_bales[j];
            largest_gap_idx = j;
        }
    }

    return largest_gap_idx;
}


int main() {
    ifstream fin("angry.in");
    ofstream fout("angry.out");

    // Binary search for each possible 'R' value, range(0, largestx - minx)
    // Try the 'R' value, if it works, try a lower 'R' value


    // Array of possible R values will look like false false false false true true
    // Our job is to find minimum true that makes the function valid.


    // O(n log n) time complexity

    int N;
    fin >> N;

    vector<int> hay_bales;
    for (int i = 0; i < N; i++) {
        int x;
        fin >> x;

        hay_bales.push_back(x);
    }

    sort(hay_bales.begin(), hay_bales.end());

    // Finding largest gap in bales to drop cow

    int drop_idx = largest_diff(hay_bales);

    // Binary search for lowest R value
    int low = 0;
    int high = hay_bales[hay_bales.size() - 1] - hay_bales[0];

    while (low < high) {
        int mid = low + (high - low)/2;
        if (detonationPossible(mid, hay_bales, drop_idx)) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }

    double R = round(low * 10) / 10;
    fout << R << "\n";
}