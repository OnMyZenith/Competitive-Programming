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
    ll n, m; cin >> n >> m;
    vector<vector<ll>> a(n, vector<ll>(m));
    ll mx = -2e9, _i = -1, _j = -1;
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            if (ckmax(mx, a[i][j])) _i = i, _j = j;
        }
    _i++, _j++;
    dbg(_i * _j, (n - _i + 1) * _j, (m - _j + 1) * _i, (m -_j + 1) * (n - _i + 1));
    cout << max({_i * _j, (n - _i + 1) * _j, (m - _j + 1) * _i, (m -_j + 1) * (n - _i + 1)}) << '\n';
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