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
    int n; cin >> n;
    vector<int> a(n);
    int mnj = 2e9, mnm = 2e9, mi = -1, ji = -1;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (i & 1) {
            if (ckmin(mnj, a[i])) ji = i;
        } else {
            if (ckmin(mnm, a[i])) mi = i;
        }
    }
    if (n & 1) {
        cout << "Mike\n";
    } else {
        if (mnj != mnm) {
            cout << (mnj < mnm ? "Mike" : "Joe") << '\n';
        } else {
            cout << (ji < mi ? "Mike" : "Joe") << '\n';
        }
    }
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