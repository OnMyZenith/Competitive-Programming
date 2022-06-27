/* Author: OnMyZenith - https://github.com/OnMyZenith */
#include "bits/stdc++.h"
using namespace std;
using ll = long long;

#ifdef asr_debug
#include "dbg.hpp"
#else
#define dbg(...) 007
#endif

template <class T> bool ckmin(T &x, const T &y) { return (y < x) ? (x = y, 1) : 0; }
template <class T> bool ckmax(T &x, const T &y) { return (y > x) ? (x = y, 1) : 0; }

void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int best = 1e9, ans = -1;
    for (int l = 0, r = k; r < n; l++, r++) {
        if(ckmin(best, max(a[r] - (a[l] + a[r]) / 2, (a[l] + a[r] + 1) / 2 - a[l]))) {
            if (a[r] - (a[l] + a[r]) / 2 > (a[l] + a[r] + 1) / 2 - a[l]) ans = (a[l] + a[r]) / 2;
            else ans = (a[l] + a[r] + 1) / 2;
        }
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