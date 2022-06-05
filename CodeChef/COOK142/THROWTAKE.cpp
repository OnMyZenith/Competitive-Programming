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
    vector<int> c(n + 1);
    vector<int> v(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    for (int i = 0; i < n; i++) cin >> v[i];

    // vector<array<ll, 2>> res(n + 1, {0, 0});
    // res[n][0] = (c[n - 1] & 1 ? v[n - 1] : 0);
    // res[n][1] = (c[n - 1] & 1 ? -v[n - 1] : 0);
    // for (int i = n - 1; i >= 0; i--) {
    //     if(c[i] & 1) {
    //         res[i][0] = max(res[i + 1][1] + v[i], res[i + 1][0]);
    //         res[i][1] = min(res[i + 1][0] - v[i], res[i + 1][1]);
    //     } else {
    //         res[i] = res[i + 1];
    //     }
    // }
    // cout << res[0][0] << '\n';

    vector<int> take;
    int mx = 0;
    for (int i = n - 1; i >= 0; i--) {
        if(c[i] & 1 && ckmax(mx, v[i])) take.push_back(v[i]);
    }
    reverse(take.begin(), take.end());
    ll ans = 0;
    int m =  (int)take.size();
    dbg(take);
    bool turn = 0;
    for (int i = 0; i < m; i++) {
        if((m - i) % 2 == 0) {
            if (!(take[i] > (i + 1 == m - 1 ? 0 : take[i + 1]) + take[m - 1])) i++;
        }
        ans += ((turn = !turn) ? take[i] : -take[i]);
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