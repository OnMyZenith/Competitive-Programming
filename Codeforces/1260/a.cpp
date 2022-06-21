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

    ll n; cin >> n;
    for (int i = 0; i < n; i++) {
        ll c, sum; cin >> c >> sum;
        ll r = sum % c;
        cout << (c - r) * (sum / c) * (sum / c) + r * (sum / c + 1) * (sum / c + 1) << '\n';
    }

    return 0;
}