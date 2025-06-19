#include <iostream>
#include <algorithm>
#include <set>
#include <cstdio>
#include <unordered_map>

using namespace std;

int main() {
    freopen("triangles.in", "r", stdin);
    freopen("triangles.out", "w", stdout);
    
    
    int n;
    cin >> n;
    
    unordered_map<int, set<int>> ymap;
    unordered_map<int, set<int>> xmap;
    int x, y;
    
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        
        xmap[x].insert(y);
        ymap[y].insert(x);
    }
    
    set<int> yset;
    int maxarea = 0, height = 0, width = 0;
    
    for (const auto& [key, value] : ymap) {
        if (value.size() <= 1) {
            continue;
        }
        
        for (const auto& xx : value) {
            yset = xmap[xx];
            if (yset.size() <= 1) {
                continue;
            }
            height = max(abs(key - *yset.begin()), abs(key - *yset.rbegin()));
            width = max(abs(xx - *value.begin()), abs(xx - *value.rbegin()));
            maxarea = max(maxarea, height * width);   
        }
        
    }
    cout << maxarea;
    
}    
