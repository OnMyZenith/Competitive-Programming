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


template <class T> bool ckmin(T &x, const T &y) { return (y < x) ? (x = y, 1) : 0; }
template <class T> bool ckmax(T &x, const T &y) { return (y > x) ? (x = y, 1) : 0; }


void solve(int _TC) {
    int n, p; cin >> n >> p;
    vector<vector<int>> b(n, vector<int> (p));
    vector<pair<ll, ll>> a(n);
    for (int i = 0; i < n; i++) {
        int mx = -1, mn = 2e9;
        for (int j = 0; j < p; j++) {
            cin >> b[i][j];
            ckmin(mn, b[i][j]);
            ckmax(mx, b[i][j]);
        }
        a[i] = {mn, mx};
    }
    vector<vector<ll>> dp(n, vector<ll>(2, (ll)4e18));
    dp[0][0] = a[0].second + a[0].second - a[0].first;
    dp[0][1] = a[0].second;
    for (int i = 1; i < n; i++) {
        dp[i][0] = min(dp[i - 1][0] + abs(a[i].second - a[i - 1].first) + a[i].second - a[i].first,
                    dp[i - 1][1] + abs(a[i].second - a[i - 1].second) + a[i].second - a[i].first);
        dp[i][1] = min(dp[i - 1][0] + abs(a[i].first - a[i - 1].first) + a[i].second - a[i].first,
                    dp[i - 1][1] + abs(a[i].first - a[i - 1].second) + a[i].second - a[i].first);
    }
    dbg(dp);

    cout << "Case #" << _TC << ": ";
    cout << min(dp[n - 1][0], dp[n - 1][1]) << '\n';
}

int main() {
    vamos;

    int TT = 1;
    cin >> TT;
    for (int TC = 1; TC <= TT; TC++) {
        solve(TC);
    }

    return 0;
}