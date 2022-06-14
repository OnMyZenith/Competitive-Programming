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
    int n, s; cin >> n >> s;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<int> pre(n + 1);
    for (int i = 0; i < n; i++) {
        pre[i + 1] = pre[i] + a[i];
    }
    if(pre[n] < s) {
        cout << -1 << '\n';
        return;
    }

    cout << n - lt(0, n, [&](int len) -> bool {
        bool works = 0;
        for (int i = 0; i + len <= n; i++) {
            works |= pre[i + len] - pre[i] <= s;
        }
        return works;
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