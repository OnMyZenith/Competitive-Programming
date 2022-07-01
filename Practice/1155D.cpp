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

const ll INF = 4e18;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << setprecision(15) << fixed;

    ll n, x; cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<array<array<ll, 3>, 3>> dp(n + 1);
    for (int i = 0; i < n; i++) for (int j = 0; j < 3; j++) for (int k = 0; k < 3; k++) dp[i][j][k] = -INF;
    dp[0][0][0] = 0;

    // dp[i][{max_seg_not_started_yet, running, over}][{yet_to_use_x, using, used}];
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                if (dp[i][j][k] == -INF) continue;

                if (j < 2) ckmax(dp[i][j + 1][k], dp[i][j][k]);
                if (k < 2) ckmax(dp[i][j][k + 1], dp[i][j][k]);

                if (i < n) dp[i + 1][j][k] = dp[i][j][k] + (j == 1 ? a[i] : 0) * (k == 1 ? x : 1);
            }
        }
    }
    cout << dp[n][2][2] << '\n';

    return 0;
}