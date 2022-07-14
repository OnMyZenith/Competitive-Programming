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

    int n; cin >> n;

    vector<vector<array<ll, 2>>> dp(n, vector<array<ll, 2>>(n));
    for (int i = 0; i < n; i++) cin >> dp[i][i][1];

    for (int l = n - 1; l >= 0; l--) {
        for (int r = l + 1; r < n; r++) {
            // MY Score when it's my turn
            dp[l][r][1] = max(dp[l + 1][r][0] + dp[l][l][1], dp[l][r - 1][0] + dp[r][r][1]);

            // MY Score when it's their turn
            dp[l][r][0] = min(dp[l + 1][r][1], dp[l][r - 1][1]);
        }
    }
    cout << dp[0][n - 1][1] << '\n';
    return 0;
}
