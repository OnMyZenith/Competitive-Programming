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

    int n; cin >> n;
    vector<int> dp(n);
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (int j = 0; j < n; j++)  {
            if (s[j] == '.') {
                dp[j] += (j ? dp[j - 1] : 0);
                if (dp[j] >= MOD) dp[j] -= MOD;
            } else dp[j] = 0;
        }
    }
    cout << dp[n - 1] << '\n';

    return 0;
}
