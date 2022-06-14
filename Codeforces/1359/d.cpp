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

const int inf = 2e9;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << setprecision(15) << fixed;

    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int MX = max(*max_element(a.begin(), a.end()), 0) + 1;
    vector<vector<int>> dp(n, vector<int> (MX, -inf));
    for (int i = 0; i < MX; i++) {
        if(i == a[0]) {
            dp[0][i] = 0;
        } else
            dp[0][i] = -inf;
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < MX; j++) {
            if(a[i] <= j) {
                ckmax(dp[i][j], dp[i - 1][j] + a[i]);
            } else {
                ckmax(dp[i][a[i]], dp[i - 1][j] + j);
            }
        }
        if(a[i] > 0) ckmax(dp[i][a[i]], 0);
    }
    int ans = 0;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < MX; j++) {
            ckmax(ans, dp[i][j]);
        }
    }
    // dbg(dp);
    cout << ans << '\n';
    return 0;
}