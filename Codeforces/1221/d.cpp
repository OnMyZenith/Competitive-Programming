/* Author: OnMyZenith - https://github.com/OnMyZenith */
#include "bits/stdc++.h"
using namespace std;
using ll = long long;

#ifdef asr_debug
#include "dbg.hpp"
#else
#define dbg(...) 007
#endif

const ll INF = 4e18;
template <class T> bool ckmin(T &x, const T &y) { return (y < x) ? (x = y, 1) : 0; }
template <class T> bool ckmax(T &x, const T &y) { return (y > x) ? (x = y, 1) : 0; }

void solve() {
    int n; cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }
    vector<array<ll, 3>> dp(n, array<ll, 3>{INF, INF, INF});
    dp[0] = {0, b[0], 2 * b[0]};
    for (int i = 1; i < n; i++) {

        if (a[i] != a[i - 1]) dp[i][0] = dp[i - 1][0];
        if (a[i] != a[i - 1] + 1) ckmin(dp[i][0], dp[i - 1][1]);
        if (a[i] != a[i - 1] + 2) ckmin(dp[i][0], dp[i - 1][2]);


        if (a[i] + 1 != a[i - 1]) dp[i][1] = b[i] + dp[i - 1][0];
        if (a[i] + 1 != a[i - 1] + 1) ckmin(dp[i][1], b[i] + dp[i - 1][1]);
        if (a[i] + 1 != a[i - 1] + 2) ckmin(dp[i][1], b[i] + dp[i - 1][2]);

        if (a[i] + 2 != a[i - 1]) dp[i][2] = 2 * b[i] + dp[i - 1][0];
        if (a[i] + 2 != a[i - 1] + 1) ckmin(dp[i][2], 2 * b[i] + dp[i - 1][1]);
        if (a[i] + 2 != a[i - 1] + 2) ckmin(dp[i][2], 2 * b[i] + dp[i - 1][2]);
    }
    cout << min(dp[n - 1][0], dp[n - 1][1]) << '\n';
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