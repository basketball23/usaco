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
    
    vector<long long> rental_prefix(R + 1);
    rental_prefix[0] = 0;
    for (int i = 1; i <= R; i++) {
        rental_prefix[i] = rental_prefix[i - 1] + rentals[i - 1];
    }

    vector<long long> milk_prefix(N);
    milk_prefix[0] = milk[0];
    for (int i = 1; i < N; i++) {
        milk_prefix[i] = milk_prefix[i - 1] + milk[i];
    }

    vector<long long> milk_profit(N + 1);
    int store_idx = 0;
    int store_amt_left = stores[0].second;

    for (int i = 0; i < N; ++i) {
        long long gallon = milk[i];
        long long profit = 0;

        while (gallon > 0 && store_idx < M) {
            int use = min((long long)store_amt_left, gallon);
            profit += 1LL * use * stores[store_idx].first;
            gallon -= use;
            store_amt_left -= use;

            if (store_amt_left == 0 && store_idx + 1 < M) {
                store_idx++;
                store_amt_left = stores[store_idx].second;
            }
        }

        milk_profit[i + 1] = milk_profit[i] + profit;
    }

    // max() to find if it's larger than currently

    long long current_profit;

    for (int i = 0; i <= N; i++) {
        int rent_cows = N - i;
        rent_cows = min(rent_cows, R);

        max_profit = max(max_profit, milk_profit[i] + rental_prefix[rent_cows]);
    }

    fout << max_profit << "\n";
    return 0;
}