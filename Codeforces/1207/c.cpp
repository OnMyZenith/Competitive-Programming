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
    int n, a, b; cin >> n >> a >> b;
    string s; cin >> s;

    vector<array<ll, 2>> dp(n + 1, array<ll, 2>{INF, INF});
    dp[0] = {b, INF};
    for (int i = 1; i <= n; i++) {
        if (s[i - 1] == '0' && (i == n || s[i] == '0')) {
            dp[i][0] = min(dp[i - 1][0] + a + b, dp[i - 1][1] + 2 * a + b);
        }
        dp[i][1] = min(dp[i - 1][0] + 2 * b + 2 * a, dp[i - 1][1] + 2 * b + a);
    }
    cout << dp[n][0] << '\n';
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