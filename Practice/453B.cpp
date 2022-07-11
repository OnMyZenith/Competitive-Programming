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

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << setprecision(15) << fixed;

    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<vector<int>> dp(n + 1, vector<int>(1 << 17, 1e9));
    vector<vector<int>> res(n + 1, vector<int>(1 << 17));
    vector<vector<int>> from(n + 1, vector<int>(1 << 17));
    dp[0][0] = 0;
    array<int, 17> p{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59};
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < 60; j++) {
            int cost = abs(a[i - 1] - j);
            int need = 0;
            for (int k = 0; k < 17; k++) {
                if (j % p[k] == 0) need |= 1 << k;
            }
            for (int mask = 0; mask < 1 << 17; mask++) {
                if (!(mask & need)) if (ckmin(dp[i][need | mask], dp[i - 1][mask] + cost)) res[i][need | mask] = j, from[i][need | mask] = mask;
            }
        }
    }
    int curr_mask = int(min_element(dp[n].begin(), dp[n].end()) - dp[n].begin());
    vector<int> ans;
    for (int i = n; i > 0; curr_mask = from[i--][curr_mask]) {
        ans.push_back(res[i][curr_mask]);
    }
    reverse(ans.begin(), ans.end());
    for (int i = 0; i < n; i++) cout << ans[i] << " \n"[i == n - 1];
    return 0;
}