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

    int curr_wall_count = 10e9;
    int adjustions = 0;


    vector<Measurement> measurements(N);
    for (int i = 0; i < N; i++) {fin >> measurements[i].day >> measurements[i].id >> measurements[i].chg;}
    sort(measurements.begin(), measurements.end(), [](Measurement& a, Measurement& b) {
        return a.day < b.day;
    });


    unordered_map<int, int> map;
    priority_queue<int> pq;
    for (int i = 0; i < N; i++) {
        Measurement curr = measurements[i];

        if (map.find(curr.id) == map.end()) {
            map[curr.id] = G + curr.chg;
        }
        pq.push(map[curr.id]);


        int top = pq.top();
        if (top > G) {
            
        }
    }

    fout << adjustions << "\n";
}