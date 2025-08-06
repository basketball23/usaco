#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ifstream fin("diamond.in");
    ofstream fout("diamond.out");

    int N, K;
    fin >> N >> K;

    vector<int> diamonds;

    for (int i = 0; i < N; i++) {
        int d;
        fin >> d;
        diamonds.push_back(d);
    }

    sort(diamonds.begin(), diamonds.end());

    // two pointers, keep track of how many elements in largest and second largest possible subarrays. Sum, and get answer

    int first = 0;
    int left = 0;

    int l, r;

    // inital pass

    for (int right = 0; right < N; right++) {
        while (diamonds[right] - diamonds[left] > K) {
            left++;
        }
        
        int elements = right - left + 1;

        if (elements > first) {
            first = elements;
            l = left;
            r = right;
        }
    }

    int second = 0;
    left = 0;

    // second pass to find second largest subarray, accounting for already used diamonds
    
    for (int right = 0; right < N; right++) {

        while (diamonds[right] - diamonds[left] > K) {
            left++;
        }
        
        if (right >= l && right <= r) {
            left = r + 1;
            continue;
        }
        
        int elements = right - left + 1;

        if (elements > second) {
            second = elements;
        }
    }

    fout << first + second << "\n";

}