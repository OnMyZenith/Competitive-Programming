/* Author: OnMyZenith - https://github.com/OnMyZenith */
#include "bits/stdc++.h"
using namespace std;
using ll = long long;

#ifdef asr_debug
#include "dbg.hpp"
#else
#define dbg(...) 007
#endif

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << setprecision(15) << fixed;

    int n; cin >> n;
    vector<int> a(n);
    vector<ll> pre(n + 1);
    for (int i = 0; i < n; i++) cin >> a[i], pre[i + 1] = pre[i] + a[i];

    ll mx = 0;
    for (int i = 0; i < n; i++) {
        mx = max(mx, (pre[i + 1] + i) / (i + 1));
    }
    int q; cin >> q;
    while (q--) {
        int t; cin >> t;
        cout << (t < mx ? -1 : (pre[n] + t - 1) / t) << '\n';
    }

    return 0;
}