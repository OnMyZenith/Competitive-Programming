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
    ll a, b, q; cin >> a >> b >> q;
    if (a == b) {
        while (q--) {
            ll l, r; cin >> l >> r;
            cout << "0" << " \n"[!q];
        }
        return;
    }

    if (a > b) swap(a, b);
    ll g = gcd(a, b);
    a /= g;

    auto calc = [&](ll lim) -> ll {
        return b * (lim / (a * b)) + min((lim % (a * b) + 1), b);
    };
    dbg(calc(70), calc(72), calc(77), calc(79), calc(80));
    while (q--) {
        ll l, r; cin >> l >> r;
        cout << r - l + 1 - (calc(r) - calc(l - 1)) << " \n"[!q];
    }

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