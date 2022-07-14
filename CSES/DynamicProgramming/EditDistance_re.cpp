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

const int N = 5e3 + 7;
int dp[N][N];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << setprecision(15) << fixed;

    string s, t;
    cin >> s >> t;
    int n = (int)s.size(), m = (int)t.size();
    memset(dp, -1, sizeof(dp));

    dp[0][0] = 0;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (dp[i][j] == -1) dp[i][j] = N;
            if (i && j) {
                if (s[i - 1] == t[j - 1]) ckmin(dp[i][j], dp[i - 1][j - 1]);
                else ckmin(dp[i][j], dp[i - 1][j - 1] + 1);
            }
            if (j) ckmin(dp[i][j], dp[i][j - 1] + 1);
            if (i) ckmin(dp[i][j], dp[i - 1][j] + 1);
        }
    }
    cout << dp[n][m] << '\n';
    return 0;
}
