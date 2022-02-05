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

int main() {
    vamos;
    int n; string s, t = "hard"; cin >> n >> s;
    vector<int> A(n); for (int i = 0; i < n; i++) cin >> A[i];
    vector<vector<ll>> dp(n+1, vector<ll>(5, 1e18)); dp[0][0] = 0;
    // dp[i][j] => min cost of first i letters if s with j letters matching with t
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 4; j++) {
            if(s[i-1] != t[j]) ckmin(dp[i][j], dp[i-1][j]);
            else{
                ckmin(dp[i][j+1], dp[i-1][j]);
                ckmin(dp[i][j], dp[i-1][j] + A[i-1]);
            }
        }
    }
    cout << *min_element(dp[n].begin(), dp[n].end() - 1) << '\n';
    return 0;
}