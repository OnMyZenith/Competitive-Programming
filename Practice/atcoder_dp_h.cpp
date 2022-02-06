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

const int MOD = 1e9 + 007; // 998244353;

int main() {
    vamos;

    int h, w; cin >> h >> w;
    vector<string> g(h);
    for (auto &s : g) {
        cin >> s;
    }
    vector<vector<int>> dp(h, vector<int>(w, 0)); dp[0][0] = 1;
    auto v = [&](int i, int j)->int{
        if(i<0||j<0) return 0;
        if(g[i][j]=='#') return 0;
        return dp[i][j];
    };
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            dp[i][j] += v(i-1,j) + v(i,j-1);
            if(dp[i][j] >= MOD) dp[i][j] -= MOD;
        }
    }
    cout << dp[h-1][w-1] << '\n';
    return 0;
}