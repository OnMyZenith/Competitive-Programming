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
    int h, n; cin >> h >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int ans = 0, curr = h;
    for (int i = 1; i < n; i++) {
        if (curr == a[i]) continue;
        if (a[i] + 1 < curr) {
            curr = a[i] + 1;
        }

        if (i < n - 1) {
            ans += a[i + 1] != a[i] - 1;
            curr = a[i] - 1;
        } else if (i == n - 1) {
            ans += a[i] != 1;
            break;
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