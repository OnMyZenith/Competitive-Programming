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

const int N = 3007;

void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int best = N;
    for (int tar = 0; tar < N; tar++) {
        int mx = 0, mn = N;
        for (int i = 0; i < n; i++) {
            if (tar == 0) {
                ckmax(mx, a[i] / k);
                ckmin(mn, a[i] / k);
            } else {
                ckmax(mx, a[i] / min(max((a[i]) / tar, 1), k));
                ckmin(mn, a[i] / min(max((a[i]) / tar, 1), k));
            }
        }
        ckmin(best, mx - mn);
    }
    cout << best << '\n';
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
