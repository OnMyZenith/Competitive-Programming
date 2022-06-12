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
    ll m, d, w;
    cin >> m >> d >> w;
    if (d == 1 || m == 1) {
        cout << 0 << '\n';
        return;
    }
    ll x = w / gcd(w, d - 1);
    ll ub = min(m, d);
    ll lb = ub - x * (ub / x);
    ll n = (ub - lb) / x;
    cout << n * lb + n * (n - 1) * x / 2 << '\n';
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