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
    ll n, l, r; cin >> n >> l >> r;
    vector<ll> a(n);
    bool poss = 1;
    for (ll i = n - 1; i >= 0 && poss; i--) {
        ll x = i + 1;
        ll lo = 1, hi = 1e9;
        while(lo < hi) {
            ll mid = (lo + hi) / 2;
            if (mid * x >= l) hi = mid;
            else lo = mid + 1;
        }
        if (lo * x <= r) {
            a[i] = x * lo;
        } else poss = 0;
    }

    if (poss) {
        cout << "YES\n";
        for (ll i = 0; i < n; i++) cout << a[i] << " \n"[i == n - 1];
    } else 
        cout << "NO\n";




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
