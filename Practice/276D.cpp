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

constexpr int log_2(ll x) { return x ? (8 * (int)sizeof(x)) - 1 - __builtin_clzll(x) : -1; } // Floor of log_2(x); index of highest 1-bit

void solve() {
    ll l, r; cin >> l >> r;

    while(l && __builtin_clzll(l) == __builtin_clzll(r)) {
        ll x = log_2(l);
        r -= 1LL << x;
        l -= 1LL << x;
    }
    ll ans = 1;
    while(ans <= r) ans *= 2;
    cout << ans - 1 << '\n';
}

int main() {
    vamos;

    int TT = 1;
    // cin >> TT;
    while(TT--) {
        solve();
    }

    return 0;
}