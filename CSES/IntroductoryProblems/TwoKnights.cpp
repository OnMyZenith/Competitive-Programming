#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long k;
    cin >> k;

    for (long long n = 1; n <= k; n++) {
        cout << (n * n * (n * n - 1) / 2) - 4 * (n - 1) * (n - 2) << "\n";
    }

    return 0;
}