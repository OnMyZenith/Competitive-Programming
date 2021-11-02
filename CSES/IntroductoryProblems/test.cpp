#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long digits = 1, k = 672274832941907421;

    while (k > ((pow(10, digits)) - 1)) // k> 1, 9, 189,.....
        digits++;
    cout << digits << "\n";
    cout << pow(10, digits) << "\n";

    return 0;
}