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


int main() {
    vamos;
    
    string s, t; int n, m;
    cin >> s >> t;
    n = ((int)s.size());
    m = ((int)t.size());
    vector<vector<pair<int,pair<int,int>>>> dp(n + 1, vector<pair<int, pair<int, int> >>(m + 1, {0, {-1, -1}}));
    // dp[i][j][0] -> max length of the LCS upto {i - 1, j - 1} <-- 0 based indices
    // dp[i][j][1] -> indices that gave the last match

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if(s[i] == t[j]) {
                if(ckmax(dp[i + 1][j + 1].first, dp[i][j].first + 1)){
                    dp[i + 1][j + 1].second = {i, j};
                }
            }
            if(ckmax(dp[i + 1][j].first, dp[i][j].first)){
                dp[i + 1][j].second = dp[i][j].second;
            }
            if(ckmax(dp[i][j + 1].first, dp[i][j].first)){
                dp[i][j + 1].second = dp[i][j].second;
            }
        }
    }
    string r;
    pair<int,int> last = dp[n][m].second; int mx = dp[n][m].first;
    for (auto &row : dp) {
        for (auto &val : row) {
            if(ckmax(mx, val.first)) last = val.second;
        }
    }
    while(last != make_pair(-1, -1)){
        r += s[last.first];
        last = dp[last.first][last.second].second;
    }
    reverse(r.begin(), r.end());
    cout << r << '\n';
    return 0;
}