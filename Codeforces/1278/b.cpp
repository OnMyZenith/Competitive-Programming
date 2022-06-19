/* Author: OnMyZenith - https://github.com/OnMyZenith */
#include "bits/stdc++.h"
using namespace std;
using ll = long long;

#ifdef asr_debug
#include "dbg.hpp"
#else
#define dbg(...) 007
#endif

// Check result <= hi
template <class T, class U> T ft(T lo, T hi, U f) {
    ++hi, assert(lo <= hi);
    while (lo < hi) {
        T mid = lo + (hi - lo) / 2;
        f(mid) ? hi = mid : lo = mid + 1;
    }
    return lo;
}

void solve() {
    ll a, b; cin >> a >> b;
    if (a < b) swap(a, b);
    ll x = ft(0ll, ll(1e9), [&](ll x) -> bool {
        return x * (x + 1) / 2 >= (a - b);
    });
    while ((x * (x + 1) / 2 - (a - b)) & 1) {
        x++;
    }
    cout << x << '\n';
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