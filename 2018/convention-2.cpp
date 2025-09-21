#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

struct Cow {
    int a;
    int t;
    int idx;
};

int main() {
    ifstream fin("convention2.in");
    ofstream fout("convention2.out");

    int N;
    fin >> N;

    vector<Cow> cows(N);

    for (int i = 0; i < N; i++) {
        fin >> cows[i].a >> cows[i].t;

        cows[i].idx = i;
    }
    sort(cows.begin(), cows.end(), [](const Cow &a, const Cow &b) {
        return a.a < b.a;
    });

    auto cmp = [](const Cow &a, const Cow &b) {
        return a.idx > b.idx;
    };
    priority_queue<Cow, vector<Cow>, decltype(cmp)> pq(cmp);

    int max_waited = 0;
    int time = 0;
    int i = 0;

    while (i < N || !pq.empty()) {
        while (i < N && cows[i].a <= time) {
            pq.push(cows[i]);
            i++;
        }

        if (pq.empty()) {
            time = cows[i].a;
            continue;
        }

        Cow curr = pq.top();
        pq.pop();

        max_waited = max(max_waited, time - curr.a);
        time += curr.t;
    }

    fout << max_waited << "\n";
}