#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

struct Measurement {
    int day;
    int id;
    int chg;
};

int main() {
    ifstream fin("measurement.in");
    ofstream fout("measurement.out");

    int N, G;
    fin >> N >> G;


    vector<Measurement> measurements(N);
    for (int i = 0; i < N; i++) {fin >> measurements[i].day >> measurements[i].id >> measurements[i].chg;}
    sort(measurements.begin(), measurements.end(), [](Measurement& a, Measurement& b) {
        return a.day < b.day;
    });

    int prev_wall_count = 10e9;
    int curr_wall_count = 10e9;
    int adjustions = 0;

    unordered_map<int, int> map;
    for (int i = 0; i < N; i++) {
        priority_queue<int> pq;
        Measurement curr = measurements[i];

        if (map.find(curr.id) == map.end()) {
            map[curr.id] = G + curr.chg;
        }
        
        for (const auto& pair : map) {
            pq.push(pair.second);
        }


        int top = pq.top();
        if (top > G) {
            pq.pop();
            curr_wall_count = 1;

            while (pq.top() == top) {
                curr_wall_count++;
                pq.pop();
            }
        } else if (top == G) {
            int salvage = 0;
            while (pq.top() == G) {
                salvage++;
                pq.pop();
            }

            curr_wall_count = prev_wall_count - pq.size() + salvage;
        } else {
            curr_wall_count = prev_wall_count - pq.size();
        }

        if (curr_wall_count != prev_wall_count) {
            adjustions++;
        }
    }

    fout << adjustions << "\n";
}