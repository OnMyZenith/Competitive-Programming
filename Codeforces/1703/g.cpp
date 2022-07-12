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

const ll inf = 4e18;
const int MX = 32;

void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<vector<ll>> dp(n + 1, vector<ll>(MX, -inf));
    for (int i = 0; i < MX; i++) dp[0][i] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < MX; j++) {
            if (j) ckmax(dp[i][j], dp[i - 1][j - 1] + a[i - 1] / (1 << j));
            ckmax(dp[i][j], dp[i - 1][j] + a[i - 1] / (1 << j) - k);
        }
        ckmax(dp[i][MX - 1], dp[i - 1][MX - 1]);
    }
    ll ans = 0;
    for (int i = 0; i < MX; i++) ckmax(ans, dp[n][i]);
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
