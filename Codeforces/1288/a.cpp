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
    ll n, d; cin >> n >> d;
    ll x = sqrt((long double)d);
    bool f = 0;
    for (ll i = -2; i < 4; i++) {
        ll y = max(x + i, 0ll);
        f |= y + (d + y) / (y + 1) <= n;
    }
    cout << (f ? "YES" : "NO") << '\n';
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