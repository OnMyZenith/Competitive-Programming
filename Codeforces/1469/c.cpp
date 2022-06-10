/* Author: OnMyZenith - https://github.com/OnMyZenith */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef asr_debug
#include "dbg.hpp"
#else
#define dbg(...) 007
#endif


void solve() {
    ll n, k; cin >> n >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<array<ll, 2>> range(n);

    range[0] = {1 + a[0], a[0] + k};
    range[n - 1] = {1 + a[n - 1], a[n - 1] + k};
    bool fail = 0;
    for (int i = 1; i < n; i++) {
        if(i < n - 1) range[i] = {max(range[i - 1][0] - (k - 1), a[i] + 1), min(range[i - 1][1] + k - 1, a[i] + 2 * k - 1)};
        fail |= range[i][0] > range[i - 1][1] || range[i][1] < range[i - 1][0];
    }
    cout << (fail ? "NO" : "YES") << '\n';
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