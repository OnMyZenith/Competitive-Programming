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
const int N = 10;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << setprecision(15) << fixed;

    int n, m; cin >> n >> m;
    
    vector<pair<int, int>> dp(1 << n);
    for (int i = 1; i < 1 << n; i++) dp[i].first = i;
    auto dp_curr = dp;
    dp[0].second = 1;

    for (int _ = 0; _ < m; _++)  {
        for (int mask = 0; mask < 1 << n; mask++) {
            int cnt = dp[mask].second;
            auto need = ~mask;
            need &= (1 << n) - 1;

            int poss = 0;
            for (int i = 0; i < n - 1; i++) {
                if (((need >> i) & 3) == 3) {
                    poss |= 1 << i;
                }
            }

            int sub_poss = poss;
            while (sub_poss) {
                bool fail = 0;
                for (int i = 0; i < n - 1 && !fail; i++) {
                    if (((sub_poss >> i) & 3) == 3) {
                        fail = 1;
                    }
                }
                if (!fail) {
                    auto sub_need = need;
                    for (int i = 0; i < n - 1; i++) {
                        if ((sub_poss >> i) & 1) {
                            sub_need ^= 3 << i;
                        }
                    }
                    dp_curr[sub_need].second += cnt;
                    if (dp_curr[sub_need].second >= MOD) dp_curr[sub_need].second -= MOD;
                }
                sub_poss = (sub_poss - 1) & poss;
            }
            // sub_poss = 0 => sub_need = need;
            dp_curr[need].second += cnt;
            if (dp_curr[need].second >= MOD) dp_curr[need].second -= MOD;
        }
        dp = dp_curr;
        for (int mask = 0; mask < 1 << n; mask++) dp_curr[mask].second = 0;
    }
    cout << dp[0].second << '\n';

    return 0;
}
