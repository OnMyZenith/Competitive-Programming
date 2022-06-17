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
    int n, m; cin >> n >> m;
    vector<int> a(n), b(m), pos(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        pos[--a[i]] = i;
    }
    for (auto &u : b) {
        cin >> u;
        u--;
    }
    int mx = -1;
    ll ans = 0;
    for (int i = 0; i < m; i++) {
        if (ckmax(mx, pos[b[i]])) {
            ans += 2 * (pos[b[i]] - i) + 1;
        } else ans++;
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