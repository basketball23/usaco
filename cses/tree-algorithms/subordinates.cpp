#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> children;
vector<int> subtree_size;

void dfs_size(int node) {
    subtree_size[node] = 1;

    for (int child : children[node]) {
        dfs_size(child);
        subtree_size[node] += subtree_size[child];
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n;
    cin >> n;

    children.resize(n);
    subtree_size.resize(n);

    for (int i = 1; i < n; i++) {
        int j;
        cin >> j;
        j--;

        children[j].push_back(i);
    }

    dfs_size(0);

    for (int i = 0; i < n; i++) {
        cout << subtree_size[i] - 1;
        if (i != n - 1) {
            cout << " ";
        }
    }

    cout << "\n";
}