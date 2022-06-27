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
    ll n, k; cin >> n >> k;
    ll ans = 0;
    while (n) {
        if (n == 1) {
            ans++;
            break;
        }
        if (n >= k) ans += n % k + 1;
        else {
            ans += n;
            break;
        }
        n /= k;
    }
    cout << ans << '\n';
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