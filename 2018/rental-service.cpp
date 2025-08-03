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

    fin >> N >> M >> R;

    vector<int> milk(N);
    vector<pair<int, int>> stores(M);
    vector<int> rentals(R);

    for (int i = 0; i < N; i++) {
        int c;
        fin >> c;
        milk[i] = c;
    }

    for (int i = 0; i < M; i++) {
        int q, p;
        fin >> q >> p;
        stores[i] = {p, q};
    }

    for (int i = 0; i < R; i++) {
        int r;
        fin >> r;
        rentals[i] = r;
    }

    // sort
    sort(milk.rbegin(), milk.rend());
    sort(stores.rbegin(), stores.rend());
    sort(rentals.rbegin(), rentals.rend()); 
    
    vector<long long> rental_prefix(R);
    rental_prefix[0] = rentals[0];
    for (int i = 1; i < R; i++) {
        rental_prefix[i] = rental_prefix[i - 1] + rentals[i];
    }

    vector<long long> milk_prefix(N);
    milk_prefix[0] = milk[0];
    for (int i = 1; i < N; i++) {
        milk_prefix[i] = milk_prefix[i - 1] + milk[i];
    }

    vector<long long> store_prefix(M);
    for (int i = 0; i < M; i++) {
        // Milk the first i cows
        // Store in total milk variable

        long long milk_avaliable = milk_prefix[i];

        // Fill store order as much as possible
        // Save as cost
        
        // while milk is still avaliable, sell to top price per gallon store
        int store_idx = 0;
        int price = 0;

        while (milk_avaliable > 0) {
            if (milk_avaliable > stores[store_idx].second) {
                milk_avaliable -= stores[store_idx].second;

                price += stores[store_idx].first * stores[store_idx].second;
            } else {
                price += stores[store_idx].first * milk_avaliable;
                milk_avaliable = 0;
                break;
            }

            store_idx++;
        }
        
        store_prefix[i] = price;
    }

    // for each i, calculate i and N - i for store and rental
    // max() to find if it's larger than currently

    long long current_profit;

    int rental_cows;
    if (R < N) {
        rental_cows = R - 1;
    } else {
        rental_cows = N - 1;
    }

    for (int i = 0; i < M; i++) {
        if (i + rental_cows >= N) {
            rental_cows -= i;
        }
        if (rental_cows < 0) {
            rental_cows = 0;
        }
        current_profit = store_prefix[i] + rental_prefix[rental_cows];
        max_profit = max(max_profit, current_profit);
    }

    fout << max_profit << "\n";
    return 0;
}