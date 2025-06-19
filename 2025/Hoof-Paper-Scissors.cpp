#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    int N, M;
    unordered_map<int, string> matchups;
    
    cin >> N >> M;
    
    string x;
    for (int i = 1; i <= N; i++) {
        cin >> x;
        matchups[i] = x;
    }
    
    int a, b;
    int winners = 0, ans = 0;
    for (int i = 1; i <= M; i++) {
        cin >> a >> b;
        
        for (const auto& pair : matchups) {
            if (pair.first > a && pair.first > b) {
                if (pair.second[a - 1] == 'W' && pair.second[b - 1] == 'W') {
                    winners++;
                }
            } else if (pair.first > a && pair.first < b) {
                if (pair.second[a - 1] == 'W' && matchups[b][pair.first - 1] == 'L') {
                    winners++;
                }
            } else if (pair.first > b && pair.first < a) {
                if (pair.second[b - 1] == 'W' && matchups[a][pair.first - 1] == 'L') {
                    winners++;
                }
            }
            
        }
        if (a > b) {
            for (int j = 0; j <= b; j++) {
                if (matchups[a][j] == matchups[b][j] && matchups[a][j] == 'L') {
                    winners++;
                }
            }
        } else {
            for (int j = 0; j <= a; j++) {
                if (matchups[a][j] == matchups[b][j] && matchups[a][j] == 'L') {
                    winners++;
                }
            }
        }
        
        ans = winners * (N - 1);
        for (int i = 1; i < winners; i++) {
            ans -= i;
        }
        ans *= 2;
        
        ans += winners;
        cout << ans << endl;
        ans = 0;
        winners = 0;
    }
}