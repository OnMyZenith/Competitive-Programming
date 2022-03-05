/* Author: OnMyZenith - https://github.com/OnMyZenith */
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
using ll = long long;

#define vamos ios_base::sync_with_stdio(false), cin.tie(nullptr), cout << setprecision(15) << fixed;
#ifdef asr_debug
#include "dbg.hpp"
#else
#define dbg(...) 007
#endif




void solve() {
    ll n; cin >> n;
    vector<ll> a(n);
    // vector<ll> idx_of(2 * n + 1, -1);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
        // idx_of[a[i]] = i;
    }

    ll ans = 0;
    for (ll i = 0; i < n; i++) {
        ll x = a[i], idx = i + 1;
        // x * y == idx + idy
        for (ll y = 1; x * y <= 2 * n; y++) {
            // x * y - idx == idy
            ll idy = x * y - idx - 1;
            if(idy >= 0 && idy < n && a[idy] != x) ans += (a[idy] == y);
        }
    }
    cout << ans / 2 << '\n';
}

int main() {
    vamos;

    int TT = 1;
    cin >> TT;
    while(TT--) {
        solve();
    }

    return 0;
}