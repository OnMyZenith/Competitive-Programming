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
    int n; cin >> n;
    vector<ll> a(n), b(n), c(n);
    for (int i = 0; i < n; i++) cin >> a[i] >> b[i];

    for (int i = 0; i < n; i++) {
        int pi = i ? i - 1 : n - 1;
        c[i] = max(a[i] - b[pi], 0ll);
    }
    ll best = 2e18;
    ll sum = accumulate(c.begin(), c.end(), 0ll);
    for (int i = 0; i < n; i++) {
        best = min(sum - c[i] + a[i], best);
    }

    cout << best << '\n';
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