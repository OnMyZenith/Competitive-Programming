/* Author: OnMyZenith - https://github.com/OnMyZenith */
#include "bits/stdc++.h"
using namespace std;
using ll = long long;

#ifdef asr_debug
#include "dbg.hpp"
#else
#define dbg(...) 007
#endif

// Check result >= lo
template <class T, class U> T lt(T lo, T hi, U f) {
    --lo, assert(lo <= hi);
    while (lo < hi) {
        T mid = lo + (hi - lo + 1) / 2;
        f(mid) ? lo = mid : hi = mid - 1;
    }
    return lo;
}

template <class T> bool ckmin(T &x, const T &y) { return (y < x) ? (x = y, 1) : 0; }
template <class T> bool ckmax(T &x, const T &y) { return (y > x) ? (x = y, 1) : 0; }

void solve() {
    ll n, s; cin >> n >> s;
    vector<ll> a(n), pre(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        pre[i + 1] = pre[i] + a[i];
    }
    if (s >= accumulate(a.begin(), a.end(), 0ll)) {
        cout << "0\n";
        return;
    }
    ll best = -1, idx = -1;
    for (int i = 0; i < n; i++) {
        if (ckmax(best, lt(0ll, n, [&](ll cnt) -> bool {
            return pre[cnt] - (cnt - 1 >= i ? a[i] : 0) <= s;
        }))) idx = i;
    }
    cout << idx + 1 << '\n';
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