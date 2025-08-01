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
    sort(milk.begin(), milk.end());
    sort(stores.begin(), stores.end());        
    sort(rentals.begin(), rentals.end()); 
    
    vector<long long> rental_prefix(N);
    rental_prefix[0] = milk[0];
    for (int i = 1; i < N; i++) {
        rental_prefix[i] = milk[i] + rental_prefix[i - 1];
    }

    reverse(milk.begin(), milk.end());

    vector<long long> milk_prefix(N);
    milk_prefix[0] = milk[0];
    for (int i = 1; i < N; i++) {
        milk_prefix[i] = milk[i] + milk_prefix[i - 1];
    }

    vector<long long> store_prefix(N);
    for (int i = 0; i < N; i++) {
        // Milk the first i cows
        // Store in total milk variable

        long long milk_avaliable = milk_prefix[i];

        // Fill store order as much as possible
        // Save as cost
        
        // while milk is still avaliable, sell to top price per gallon store
        int store_idx = M - 1;
        int price = 0;

        while (milk_avaliable > 0) {
            if (milk_avaliable > stores[store_idx].second) {
                milk_avaliable -= stores[store_idx].second;

                price += stores[store_idx].first * stores[store_idx].second;
            } else {
                price += milk_avaliable * stores[store_idx].second;
                milk_avaliable = 0;
                break;
            }

            store_idx--;
        }
        store_prefix[i] = price;
    }

    // for each i, calculate i and N - i for store and rental
    // max() to find if it's larger than currently

    for (int i = 0; i < N; i++) {
        long long current_profit = rental_prefix[i] + store_prefix[N - 1 - i];
        max_profit = max(max_profit, current_profit);
    }

    fout << max_profit << "\n";
    return 0;
}