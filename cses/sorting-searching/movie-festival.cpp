#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> movies(n);

    for (int i = 0; i < n; i++) {
        cin >> movies[i].first >> movies[i].second;
    }

    sort(movies.begin(), movies.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second < b.second;
    });

    int end_time = 0;
    int num_movies = 0;

    for (int i = 0; i < n; i++) {
        if (movies[i].first >= end_time) {
            num_movies++;
            end_time = movies[i].second;
        }
    }

    cout << num_movies << "\n";
}