#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string S;
    cin >> S;

    // Maybe bitwise again?


    // iterate through the string, and do bitwise stuff at each character?

    // USE PROPERTY THAT TWO NUMBERS WILL XOR EACH OTHER OUT IF THEY'RE THE SAME
    int ans = 0;
    int s = 0;
    vector<int> prefOdd = {1, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    vector<int> prefEven = {1, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    for (int i = 0; i < S.size(); i++) {
        int digit = S[i] - '0';

        s ^= digit;

        if ((i + 1) % 2 == 0) {
            cout << "debug :" << "digit: " << digit << " " << prefEven[s] << " " << s << "\n";
            ans += prefEven[s];

            prefEven[s]++;
        } else {
            cout << "debug :" << "digit: " << digit << " " << prefOdd[s] << " " << s << "\n";
            ans += prefOdd[s];

            prefOdd[s]++;
        }
    }
    
    cout << ans << "\n";
}