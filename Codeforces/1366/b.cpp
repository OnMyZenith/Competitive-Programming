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
    int n, x, m; cin >> n >> x >> m;
    bool s = 0;
    int L = -1, R = -1;
    while (m--) {
        int l, r; cin >> l >> r;
        if (!s && l <= x && x <= r) {
            s = 1;
            L = l, R = r;
        } else if (s) {
            if (!(L > r || l > R)) {
                L = min(l, L);
                R = max(R, r);
            }
        }
    }
    cout << R - L + 1 << '\n';
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