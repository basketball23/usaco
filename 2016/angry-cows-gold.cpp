#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

// Check if detonating with a R value works or not

// Drop the cow at the largest difference between locations in hay bales
bool detonation(int R, const vector<int>& hay_bales, int drop_idx) {
    // Iterate left
    bool still_detonating = true;
    int curr_R = R;
    int curr_idx = drop_idx;

    while (still_detonating) {
        
    }

    
    // Iterate right
}

// Function returns the indicies of largest gap in hay bales
pair<int, int> largest_diff(const vector<int>& hay_bales) {
    pair<int, int> largest_gap;
    int difference = 0;

    for (int j = 0; j < hay_bales.size() - 1; j++) {
        if (hay_bales[j + 1] - hay_bales[j] > difference) {
            difference = hay_bales[j + 1] - hay_bales[j];
            largest_gap.first = j;
            largest_gap.second = j + 1;
        }
    }

    return largest_gap;
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

    /*
    TODO: fix bug - drop_idx will just be like [(5 + 6)/2], returning 5. Write logic so that the cow is dropped in the middle of the two LOCATIONS of the haybales, not INDICIES
    */
    pair<int, int> largest_gap = largest_diff(hay_bales);
    int drop_idx = (largest_gap.first + largest_gap.second)/2;

    // Binary search for lowest R value
    int low = 0;
    int high = hay_bales[hay_bales.size() - 1] - hay_bales[0];

    int R, r;

    while (low < high) {
        int mid = low + (high - low)/2;

        r = mid;
        if (detonation(r, hay_bales, drop_idx)) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    
    R = low;
    fout << R << "\n";
}