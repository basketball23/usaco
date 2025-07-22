#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
    vector<int> xval, yval;
    int N, input;
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        cin >> input;
        xval.push_back(input);
    }
    for (int i = 0; i < N; i++) {
        cin >> input;
        yval.push_back(input);
    }
    int length = 0, width = 0, distance, largest = 0;
    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            length = abs(yval[i] - yval[j]);
            width = abs(xval[i] - xval[j]);
            
            distance = sqrt(pow(length, 2) + pow(width, 2));
            
            largest = max(distance, largest);
            
        }
    }
    cout << pow(largest, 2);
    return 0;
}