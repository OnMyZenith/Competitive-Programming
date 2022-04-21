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




void solve() {
    ll n; cin >> n;
    vector<string> a(n);
    vector<vector<ll>> f(11, vector<ll>(11));
    for (auto &u : a) {
        cin >> u;
        f[u[0] - 'a'][u[1] - 'a']++;
    }
    ll ans = n * (n - 1) / 2;
    vector<ll> r(11), c(11);

    for (ll i = 0; i < 11; i++) {
        for (ll j = 0; j < 11; j++) {
            r[i] += f[i][j];
            c[j] += f[i][j];
        }
    }
    dbg(r, c, ans);
    ll cnt = 0;
    for (ll i = 0; i < 11; i++) {
        for (ll j = 0; j < 11; j++) {
            ans -= f[i][j] * (f[i][j] - 1) / 2;
            cnt += (n - (r[i] + c[j] - f[i][j])) * f[i][j];
        }
    }
    cout << ans - cnt / 2 << '\n';
    // auto b = a;
    // for (auto &u : b) {
    //     reverse(u.begin(), u.end());
    // }
    // vector<int> idx(n);
    // iota(idx.begin(), idx.end(), 0);
    // auto ridx = idx;

    // sort(idx.begin(), idx.end(), [&](int i, int j){return a[i] < a[j];});
    // sort(ridx.begin(), ridx.end(), [&](int i, int j){return b[i] < b[j];});

    // for (int i = 0; i < n; i++) {
    //     ll cnt = 0, cnt2 = 0;
    //     for (int j = i; j < n && a[idx[i]] == a[idx[j]]; j++, cnt++) {
    //         //
    //         // dbg(a[idx[j]]);
    //     }
    //     for (int j = i + cnt; j < n && a[idx[i]][0] == a[idx[j]][0] && a[idx[i]][1] != a[idx[j]][1]; j++, cnt2++) {
    //         //
    //     }
    //     dbg(cnt, cnt2, a[idx[i]], a[idx[i + cnt + cnt2 - 1]]);
    //     i += cnt + cnt2 - 1;
    //     ans += (((cnt2 + cnt) * ((cnt2 + cnt) - 1) / 2)) - (cnt * (cnt - 1) / 2);
    //     // ans += cnt * (cnt2 * (cnt2 - 1) / 2);
    // }
    // dbg(ans);
    // for (int i = 0; i < n; i++) {
    //     ll cnt = 0, cnt2 = 0;
    //     for (int j = i; j < n && b[ridx[i]] == b[ridx[j]]; j++, cnt++) {
    //         //
    //         // dbg(b[ridx[j]]);
    //     }
    //     for (int j = i + cnt; j < n && b[ridx[i]][0] == b[ridx[j]][0] && b[ridx[i]][1] != b[ridx[j]][1]; j++, cnt2++) {
    //         //
    //     }
    //     dbg(cnt, cnt2, b[ridx[i]], b[ridx[i + cnt + cnt2 - 1]]);
    //     i += cnt + cnt2 - 1;
    //     ans += (((cnt2 + cnt) * ((cnt2 + cnt) - 1) / 2)) - (cnt * (cnt - 1) / 2);
    //     // ans += cnt * (cnt2 * (cnt2 - 1) / 2);
    //     // ans += cnt * cnt2;
    // }
    // for (int i = 0; i < n; i++) dbg(a[idx[i]]);
    // for (int i = 0; i < n; i++) dbg(b[ridx[i]]);
    // cout << ans << '\n';
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