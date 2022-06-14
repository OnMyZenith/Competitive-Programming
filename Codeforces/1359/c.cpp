/* Author: OnMyZenith - https://github.com/OnMyZenith */
#include "bits/stdc++.h"
using namespace std;
using ll = long long;

#ifdef asr_debug
#include "dbg.hpp"
#else
#define dbg(...) 007
#endif


void solve() {
    ll h, c, t; cin >> h >> c >> t;

    if(2 * t <= h + c) {
        cout << 2 << '\n';
        return;
    } else if (6 * (t - c) >= 5 * (h - c)) {
        cout << 1 << '\n';
        return;
    } else if (3 * (t - c) >= 2 * (h - c)) {
        cout << 3 << '\n';
        return;
    }

    ll x1 = (h - t + (2 * t - c - h - 1)) / (2 * t - c - h);
    dbg(x1);
    long double td = 1e18;
    int res = x1;
    for (int i = -2; i <= 5; i++) {
        long double x = max(x1 + i, 0ll);
        long double diff = abs(t - (long double)(h * (x + 1) + x * c) / (2 * x + 1));

        if (td > diff) {
            td = diff;
            res = 2 * x + 1;
        }
    }
    cout << res << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << setprecision(15) << fixed;

    int TT = 1;
    cin >> TT;
    while(TT--) {
        solve();
    }

    return 0;
}