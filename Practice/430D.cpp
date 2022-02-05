/* Author: OnMyZenith - https://github.com/OnMyZenith */
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
using ll = long long;

#define vamos ios_base::sync_with_stdio(false), cin.tie(nullptr), cout << setprecision(15) << fixed;
#ifdef asr_debug
#include "dbg.hpp"
#else
#define dbg(...) 007
#endif

template <class T>
bool ckmin(T &x, const T &y) { return (y < x) ? (x = y, 1) : 0; }
template <class T>
bool ckmax(T &x, const T &y) { return (y > x) ? (x = y, 1) : 0; }

int main() {
    vamos;
    int n, m;
    cin >> n >> m;
    vector<vector<ll>> a(n, vector<ll>(m));
    for (auto &row : a) {
        for (auto &e : row) {
            cin >> e;
        }
    }
    vector<vector<vector<ll>>> dp(4, vector<vector<ll>>(n, vector<ll>(m))); // {topL, topR, botL, botR}

    auto ans = [&](int i, int j) -> ll {
        ll res = 0;
        if(i && (j < m - 1) && j && i < (n - 1)){
            ckmax(res, dp[0][i][j - 1] + dp[1][i - 1][j] + dp[2][i + 1][j] + dp[3][i][j + 1]);
            ckmax(res, dp[0][i - 1][j] + dp[1][i][j + 1] + dp[2][i][j - 1] + dp[3][i + 1][j]);
        }
        return res;
    };

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            dp[0][i][j] = max((i ? dp[0][i - 1][j] : 0LL), (j ? dp[0][i][j - 1] : 0LL)) + a[i][j];
        }
    }
    for (int i = 0; i < n; i++)  {
        for (int j = m - 1; j >= 0; j--) {
            dp[1][i][j] = max((i ? dp[1][i - 1][j] : 0LL), ((j < m - 1) ? dp[1][i][j + 1] : 0LL)) + a[i][j];
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < m; j++) {
            dp[2][i][j] = max(((i < n - 1) ? dp[2][i + 1][j] : 0LL), (j ? dp[2][i][j - 1] : 0LL)) + a[i][j];
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            dp[3][i][j] = max(((i < n - 1) ? dp[3][i + 1][j] : 0LL), ((j < m - 1) ? dp[3][i][j + 1] : 0LL)) + a[i][j];
        }
    }
    ll best = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ckmax(best, ans(i, j));
        }
    }
    cout << best << '\n';
    return 0;
}