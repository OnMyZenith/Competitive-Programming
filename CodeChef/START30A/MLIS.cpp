/* Author: OnMyZenith - https://github.com/OnMyZenith */
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
using ll = long long;

#define vamos ios_base::sync_with_stdio(false), cin.tie(nullptr), cout << setprecision(15) << fixed;
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
    for (auto &u : a) {
        cin >> u;
    }
    const int INF = 1e9;
    vector<int> d(n+1, INF);
    d[0] = -INF;

    int j = 0;
    int ans = 1;
    vector<int> pre(n), suff(n);
    for (int i = 0; i < n; i++) {
        j = upper_bound(d.begin(), d.end(), a[i]) - d.begin();
        if (d[j-1] < a[i] && a[i] < d[j]){
            d[j] = a[i];
            ckmax(ans, j);
        }
        pre[i] = ans;
    }


    reverse(a.begin(), a.end());
    for (auto &u : a) {
        u = -u;
    }

    d.assign(n + 1, INF);
    d[0] = -INF;
    j = 0, ans = 1;
    for (int i = 0; i < n; i++) {
        j = upper_bound(d.begin(), d.end(), a[i]) - d.begin();
        if (d[j-1] < a[i] && a[i] < d[j]){
            d[j] = a[i];
            ckmax(ans, j);
        }
        suff[i] = ans;
    }

    int res = 0;
    for (int l = 0; l <= n; l++) {
        ckmax(res, (l ? pre[l - 1] : 0) + (l != n ? suff[n - l - 1] : 0));
    }

    cout << res << '\n';
}

int main() {
    vamos;

    int TT = 1;
    cin >> TT;
    while(TT--) {
        solve();
    }

    return 0;
}