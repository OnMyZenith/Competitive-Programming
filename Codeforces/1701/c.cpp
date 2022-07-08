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
    int n, m; cin >> n >> m;
    vector<ll> a(n);
    for (int i = 0, x; i < m; i++) {
        cin >> x; x--; a[x]++;
    }
    cout << ft(0ll, ll(1e9), [&](ll days) -> bool {
        ll rem = 0, spare = 0;
        for (int i = 0; i < n; i++) {
            spare += max(0ll, (days - a[i]) - ((days - a[i]) & 1));
            rem += max(0ll, a[i] - days);
        }
        return 2 * rem <= spare;
    }) << '\n';
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