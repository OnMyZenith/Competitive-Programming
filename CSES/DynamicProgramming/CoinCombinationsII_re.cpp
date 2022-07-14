/* Author: OnMyZenith - https://github.com/OnMyZenith */
#include "bits/stdc++.h"
using namespace std;
using ll = long long;

#ifdef asr_debug
#include "dbg.hpp"
#else
#define dbg(...) 007
#endif

const int MOD = 1e9 + 7;
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << setprecision(15) << fixed;

    int n, x; cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    n = (int)a.size();

    vector<int> dp(x + 1);
    // dp[i][val] = dp[i - 1][val] + dp[i - 1][val - a[i - 1]];
    dp[0] = 1;
    for (auto &val : a) {
        for (int tot_val = val; tot_val <= x; tot_val++) {
            dp[tot_val] += dp[tot_val - val];
            if (dp[tot_val] >= MOD) dp[tot_val] -= MOD;
        }
    }
    dbg(dp);
    cout << dp[x] << '\n';

    return 0;
}
