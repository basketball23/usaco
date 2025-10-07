#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <set>
#include <utility>

using namespace std;

struct Measurement {
    int day;
    int id;
    int chg;
};

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    ifstream fin("measurement.in");
    ofstream fout("measurement.out");

    int N, G;
    fin >> N >> G;


    vector<Measurement> measurements(N);
    for (int i = 0; i < N; i++) {
        fin >> measurements[i].day >> measurements[i].id >> measurements[i].chg;
    }

    sort(measurements.begin(), measurements.end(), [](Measurement& a, Measurement& b) {
        return a.day < b.day;
    });

    int adjustions = 0;


    unordered_map<int, int> milk;
    set<int> prev_on_wall;
    set<int> prev_not_on;

    for (int i = 0; i < N; i++) {
        set<int> on_wall;
        set<int> not_on;

        priority_queue<pair<int, int>> pq;
        Measurement curr = measurements[i];

        if (milk.find(curr.id) == milk.end()) {
            milk[curr.id] = G + curr.chg;
        } else {
            milk[curr.id] += curr.chg;
        }
        
        for (const auto& pair : milk) {
            pq.push(make_pair(pair.second, pair.first));
        }


        pair<int, int> top = pq.top();
        pq.pop();

        if (top.first == G) {
            while (!pq.empty() && pq.top().first == G) {
                pq.pop();
            }
            while (!pq.empty()) {
                not_on.insert(pq.top().second);
                pq.pop();
            }

        } else if (top.first > G) {
            on_wall.insert(top.second);
            while (!pq.empty() && pq.top().first == top.first) {
                on_wall.insert(pq.top().second);
                pq.pop();
            }
        } else {
            while (!pq.empty()) {
                not_on.insert(pq.top().second);
                pq.pop();
            }
        }


        if (on_wall != prev_on_wall || not_on != prev_not_on) {
            adjustions++;
        }
        
        prev_on_wall = on_wall;
        prev_not_on = not_on;
    }


    fout << adjustions << "\n";
}