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

    int n, m; cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<ll> diffp(n - 1), diffn(n - 1), pre(n), suff(n);
    for (int i = 0; i < n - 1; i++) {
        diffp[i] = max(a[i] - a[i + 1], 0);
        pre[i + 1] = pre[i] + diffp[i];
    }
    for (int i = n - 2; i >= 0; i--) {
        diffn[i] = max(a[i + 1] - a[i], 0);
        suff[i] = suff[i + 1] + diffn[i];
    }
    dbg(pre, suff);
    while (m--) {
        int x, y; cin >> x >> y;
        --y, --x;
        ll ans = 0;
        if (x > y) {
            ans += suff[y] - suff[x];
        } else {
            ans += pre[y] - pre[x];
        }
        cout << ans << '\n';
    }



    return 0;
}
