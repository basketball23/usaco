#include <iostream>
#include <vector>

using namespace std;

int main() {
    int T, N, K, x;
    vector<int> program;
    cin >> T;
    
    int first, index = 0;
    
    for (int i = 0; i < T; i++) {
        cin >> N >> K;
        
        for (int j = 0; j < N; j++) {
            cin >> x;
            program.push_back(x);
        }
        
        if (K == 1) {
            cout << "YES" << endl;
        } else {
            first = program[index];
            
            while (program[index + 1] == first) {
                index++;
            }
            while (program[index + 1] != first) {
                index++;
            }
            
        }
        program.clear();
        index = 0;
    }
    
    
}