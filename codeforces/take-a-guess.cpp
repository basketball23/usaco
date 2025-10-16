#include <iostream>

using namespace std;

int ask(string q, int a, int b) {
    cout << q << " " << a << " " << b;
    fflush(stdout);

    int res;
    cin >> res;

    return res;
}

int sum(int a, int b) {
    int and_ = ask("and", a, b);
    int or_ = ask("or", a, b);

    int xor_ = ~and_ & or_;

    int sum = 2 * and_ + xor_;
    return sum;
}

int main() {
    int n, k;
    cin >> n >> k;

    int sum_ab = sum(0, 1);
    int sum_bc = sum(1, 2);
    int sum_ac = sum(0, 2);

    vector<int> arr;
    int a = (sum_ab + sum_ac - sum_bc) / 2;
    int b = sum_ab - a;
    int c = sum_ac - a;

    arr.push_back(a);
    arr.push_back(b);
    arr.push_back(c);

    for (int i = 3; i < n; i++) {
        
    }

    // Use AND and XOR operators to find sum of elements
    // & bitwise AND
    // | bitwise OR
    // ^ or xor bitwise XOR
}