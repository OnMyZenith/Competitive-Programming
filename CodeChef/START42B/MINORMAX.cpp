/* Author: OnMyZenith - https://github.com/OnMyZenith */
#include <bits/stdc++.h>
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
    int n; cin >> n;
    vector<int> a(n); cin >> a[0];
    int mx = a[0], mn = a[0];
    bool f = 1;
    for (int i = 1; i < n; i++) {
        cin >> a[i];
        f &= (a[i] >= mx) || (a[i] <= mn);
        ckmin(mn, a[i]);
        ckmax(mx, a[i]);
    }
    cout << (f ? "YES" : "NO") << '\n';
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