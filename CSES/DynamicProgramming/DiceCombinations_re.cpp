/* Author: OnMyZenith - https://github.com/OnMyZenith */
#include "bits/stdc++.h"
using namespace std;
using ll = long long;

#ifdef asr_debug
#include "dbg.hpp"
#else
#define dbg(...) 007
#endif

const int MOD = 1e9 + 007; // 998244353;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << setprecision(15) << fixed;

    int n; cin >> n;
    vector<int> dp(n + 1);
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int step = 1; step <= 6 && i - step >= 0; step++) {
            dp[i] += dp[i - step];
            if (dp[i] >= MOD) dp[i] -= MOD;
        }
    }
    cout << dp[n] << '\n';
    return 0;
}
