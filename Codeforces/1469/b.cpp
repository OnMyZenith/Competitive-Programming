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
    vector<int> r(n);
    for (int i = 0; i < n; i++) cin >> r[i];
    int m; cin >> m;
    vector<int> b(m);
    for (int i = 0; i < m; i++) cin >> b[i];
    ll best = 0, curr = 0;
    for (int i = 0; i < n; i++) {
        curr += r[i];
        ckmax(best, curr);
    }
    ll rb = best; best = 0, curr = 0;
    for (int i = 0; i < m; i++) {
        curr += b[i];
        ckmax(best, curr);
    }
    cout << rb + best << '\n';
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