#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int N, U;
    cin >> N >> U;
    char arr[N][N];
    vector<int> ans;
    string a;
    for (int i = 0; i < N; i++) {
        cin >> a;
        
        for (int j = 0; j < N; j++) {
            arr[i][j] = a[j];
        }
    }
    int same = 0;
    int operations = 0;
    char s;
    
    for (int i = 0; i < N/2; i++) {
        for (int j = 0; j < N/2; j++) {
            
            s = arr[i][j];
            if (arr[N - 1 - i][j] == s) {
                same++;
            }
            if (arr[i][N - 1 - j] == s) {
                same++;
            }
            if (arr[N - 1 - i][N - 1 - j] == s) {
                same++;
            }
            
            
            if (same == 0 || same == 2) {
                operations++;
            } else if (same == 1) {
                operations += 2;
            }
            
            same = 0;
        }
    }
    //cout << operations << endl;
    ans.push_back(operations);

    int r, c, b;
    for (int x = 0; x < U; x++) {
        cin >> r >> c;
        r--;
        c--;
        
        s = arr[r][c];
        if (arr[N - 1 - r][c] == s) {
            same++;
        }
        if (arr[r][N - 1 - c] == s) {
            same++;
        }
        if (arr[N - 1 - r][N - 1 - c] == s) {
            same++;
        }
        
        b = same;
        same = 0;
        
        if (arr[r][c] == '.') {
            arr[r][c] = '#';
        } else {
            arr[r][c] = '.';
        }
        
        s = arr[r][c];
        if (arr[N - 1 - r][c] == s) {
            same++;
        }
        if (arr[r][N - 1 - c] == s) {
            same++;
        }
        if (arr[N - 1 - r][N - 1 - c] == s) {
            same++;
        }
        
        
        if (same == 0 || same == 2) {
            if (b == 1) {
                operations--;
            } else if (b == 3) {
                operations++;
            }
            
        } else if (same == 1) {
            if (b == 0 || b == 2) {
                operations++;
            }
            if (b == 3) {
                operations += 2;
            }
        } else if (same == 3) {
            if (b == 1) {
                operations -= 2;
            } else if (b == 0 || b == 2) {
                operations--;
            }
        }
        
        //cout << operations << endl;
        ans.push_back(operations);
        same = 0;
    }
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << endl;
    }
    
}