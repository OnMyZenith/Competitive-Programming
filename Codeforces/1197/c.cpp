/* Author: OnMyZenith - https://github.com/OnMyZenith */
#include "bits/stdc++.h"
using namespace std;
using ll = long long;

#ifdef asr_debug
#include "dbg.hpp"
#else
#define dbg(...) 007
#endif


int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << setprecision(15) << fixed;

    int n, k; cin >> n >> k;
    int x; cin >> x;
    int f = x;
    vector<int> diff(n - 1);
    for (int i = 1; i < n; i++) {
        int y; cin >> y;
        diff[i - 1] = y - x;
        x = y;
    }
    sort(diff.rbegin(), diff.rend());
    cout << x - f - accumulate(diff.begin(), diff.begin() + k - 1, 0ll) << '\n';

    return 0;
}