#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    //ifstream cin("cardgame.in");
    //ofstream cout("cardgame.out");

    int N;
    cin >> N;

    vector<int> elsie;

    for (int i = 0; i < N; i++) {
        int card;
        cin >> card;

        elsie.push_back(card);
    }

    vector<int> elsie_sorted = elsie;
    sort(elsie_sorted.begin(), elsie_sorted.end());

    // Build bessie's card list, already sorted
    vector<int> bessie;

    int idx = 0;
    for (int i = 1; i <= 2 * N; i++) {
        if (idx == N || i != elsie_sorted[idx]) {
            bessie.push_back(i);
            cout << i << " ";
        } else {
            cout << "increment" << " ";
            idx++;
        }
    }

    /*
    Algo:

    Split bessie's deck into two piles - the lower and the upper
    For the first N/2 rounds, play purely from the upper
    Here's GREEDY - play the smallest card that still beats Elsie (if not possible play smallest card from 'large' pile)

    For the next N/2 rounds, flip the logic
    */
    
    // Build first round and second round options
    vector<int> bessie_round1;
    for (int i = 0; i < N/2; i++) {
        bessie_round1.push_back(bessie[i]);
    }

    vector<int> bessie_round2;
    for (int i = N/2; i < N; i++) {
        bessie_round2.push_back(bessie[i]);
    }


    
}