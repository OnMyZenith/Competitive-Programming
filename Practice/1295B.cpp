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
    int n, x; cin >> n >> x;
    string s; cin >> s;
    int hi = 0, lo = 0, step = 0;
    vector<int> pre(n + 1);
    for (int i = 0; i < n; i++) {
        step += s[i] == '0' ? 1 : -1;
        ckmin(lo, step);
        ckmax(hi, step);
        pre[i + 1] = step;
    }
    if (step == 0 && x <= hi && x >= lo) {
        cout << "-1\n";
        return;
    }
    if (step == 0 && (x > hi || x < lo)) {
        cout << "0\n";
        return;
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        cnt += (x - pre[i]) / step >= 0 && ((x - pre[i]) % step == 0);
    }
    cout << cnt << '\n';
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