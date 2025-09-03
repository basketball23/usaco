#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ifstream fin("cardgame.in");
    ofstream fout("cardgame.out");

    int N;
    fin >> N;

    vector<int> elsie;

    for (int i = 0; i < N; i++) {
        int card;
        fin >> card;

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
            fout << i << " ";
        } else {
            fout << "increment" << " ";
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
    reverse(bessie_round2.begin(), bessie_round2.end());

    vector<int> elsie_round1;
    for (int i = 0; i < N/2; i++) {
        elsie_round1.push_back(elsie[i]);
    }

    vector<int> elsie_round2;
    for (int i = N/2; i < N; i++) {
        elsie_round2.push_back(elsie[i]);
    }


    // Main game logic loop
    int num_wins = 0;
    for (int i = 0; i < N/2; i++) {

        // TODO: use binary search to find lowest value that wins instead of iteration
        for (int j = 0; j < bessie_round1.size(); j++) {
            if (bessie_round1[j] > elsie[i]) {
                num_wins++;
                bessie_round1.erase(bessie_round1.begin() + j);
                break;
            }
        }
    }

    for (int i = 0; i < N/2; i++) {
        
    }



}