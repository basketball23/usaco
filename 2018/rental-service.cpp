#include <iostream>
#include <fstream>
#include <vector>
#include <utility>

using namespace std;

int main() {
    ifstream fin("rental.in");
    ofstream fout("rental.out");

    int N, M, R;

    vector<int> milk_production;
    vector<pair<int, int>> store_purchases;
    vector<int> farmer_rentals;

    fin >> N >> M >> R;

    for (int i = 0; i < N; i++) {
        int c;
        fin >> c;
        milk_production.push_back(c);
    }

    for (int i = 0; i < M; i++) {
        int q, p;
        fin >> q >> p;
        store_purchases.push_back({q, p});
    }

    for (int i = 0; i < R; i++) {
        int r;
        fin >> r;
        farmer_rentals.push_back(r);
    }


}