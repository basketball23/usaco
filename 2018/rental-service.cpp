#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main() {
    ifstream fin("rental.in");
    ofstream fout("rental.out");

    int N, M, R;
    long long max_profit = 0;
    int milk_gallons = 0;

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
        store_purchases.push_back({p, q});
    }

    for (int i = 0; i < R; i++) {
        int r;
        fin >> r;
        farmer_rentals.push_back(r);
    }

    // Start here by sorting the cow data by milk production
    // Then sort by customer demand and pricing
    // GREEDY

    sort(milk_production.begin(), milk_production.end());
    sort(store_purchases.begin(), store_purchases.end());
    sort(farmer_rentals.begin(), farmer_rentals.end());

    int milk_index = milk_production.size() - 1;
    int purchase_index = store_purchases.size() - 1;
    int rental_index = farmer_rentals.size() - 1;


    while (!milk_production.empty() && (!store_purchases.empty() || !farmer_rentals.empty())) {
        int gal = min(milk_production[milk_index] + milk_gallons, store_purchases[purchase_index].second);
        
        if ((gal * store_purchases[purchase_index].first) > farmer_rentals[rental_index]) {
            milk_gallons += milk_production[milk_index];

            milk_gallons -= gal;
            max_profit += gal * store_purchases[purchase_index].first;

            milk_production.pop_back();
            store_purchases.pop_back();
            milk_index--;
            purchase_index--;
        }
    }


}