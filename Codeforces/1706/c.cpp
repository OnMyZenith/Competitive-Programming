/* Author: OnMyZenith - https://github.com/OnMyZenith */
#include "bits/stdc++.h"
using namespace std;
using ll = long long;

#ifdef asr_debug
#include "dbg.hpp"
#else
#define dbg(...) 007
#endif


void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<ll> pre(n + 1), suff(n + 1);
    vector<int> left(n), right(n);

    for (int i = 1; i + 1 < n; i += 2) {
        left[i] = max(max(a[i - 1], a[i + 1]) - a[i] + 1, 0);
    }
    for (int i = n - 2; i >= 1; i -= 2) {
        right[i] = max(max(a[i - 1], a[i + 1]) - a[i] + 1, 0);
    }

    for (int i = 0; i < n; i++) pre[i + 1] = pre[i] + left[i];
    for (int i = n - 1; i >= 0; i--) suff[i] = suff[i + 1] + right[i];

    if (n & 1) {
        cout << pre[n] << '\n';
    } else {
        ll best = 4e18;
        for (int i = 0; i < n; i++) {
            best = min(best, pre[i] + suff[i + 1]);
        }
        cout << best << '\n';
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
