/* Author: OnMyZenith - https://github.com/OnMyZenith */
#include "bits/stdc++.h"
using namespace std;
using ll = long long;

#ifdef asr_debug
#include "dbg.hpp"
#else
#define dbg(...) 007
#endif


void solve() {
    string s, t; cin >> s >> t;
    int n = (int)s.size(), m = (int)t.size();

    for (int len = 0; len <= m; len++) {
        string t1 = t.substr(0, len);
        string t2 = t.substr(len);

        int l1 = (int)t1.size(), l2 = (int)t2.size();
        vector<vector<vector<bool>>> dp(n + 1, vector(l1 + 1, vector<bool>(l2 + 1)));
        // vector<vector<bool>> dp(l1 + 1, vector<bool>(l2 + 1));

        for (int i = 0; i <= n; i++) dp[i][0][0] = 1;

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= l1; j++) {
                for (int k = 0; k <= l2; k++) {
                    dp[i][j][k] = dp[i - 1][j][k] || dp[i][j][k] ? 1 : 0;
                    if(j && s[i - 1] == t1[j - 1]) dp[i][j][k] = (dp[i - 1][j - 1][k] || dp[i - 1][j][k] || dp[i][j][k]) ? 1 : 0;
                    if(k && s[i - 1] == t2[k - 1]) dp[i][j][k] = (dp[i - 1][j][k - 1] || dp[i - 1][j][k] || dp[i][j][k]) ? 1 : 0;
                }
            }
        }
        if (dp[n][l1][l2]) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
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