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
    vector<string> a(n);
    vector<int> cntr(n), cntc(m);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cntr[i] = (int)count(a[i].begin(), a[i].end(), '.');
    }
    for (int j = 0; j < m; j++) {
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            cnt += a[i][j] == '.';
        }
        cntc[j] = cnt;
    }
    int ans = n + m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ckmin(ans, cntr[i] + cntc[j] - (a[i][j] == '.'));
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