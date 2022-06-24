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

void solve() {
    int n; cin >> n;

    if (n < 12) {
        cout << "1337" << string(n - 1, '7') << '\n';
        return;
    }

    int cnt3 = lt(0, int(1e5), [&](int x) -> bool {
        return (ll) x * (x - 1) <= n;
    });

    int rem = n - cnt3 * (cnt3 - 1);
    cout << "133" << (rem & 1 ? "7" : "") << string(cnt3 - 4, '3') << string(rem / 2, '1') << "3377\n";
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