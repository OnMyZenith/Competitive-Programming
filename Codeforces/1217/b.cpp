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
    int n, x; cin >> n >> x;
    vector<int> a(n);
    int D = 0;
    for (int i = 0; i < n; i++) {
        int d, h; cin >> d >> h;
        D = max(D, d); a[i] = d - h;
    }
    sort(a.rbegin(), a.rend());
    if (D >= x) {
        cout << "1\n";
        return;
    }

    if (a[0] <= 0) {
        cout << "-1\n";
        return;
    }

    cout << ft(0, int(2e9), [&](int m) -> bool {
        return (ll)(m - 1) * a[0] + D >= x;
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