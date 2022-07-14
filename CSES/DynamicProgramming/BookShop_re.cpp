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

    int n, tot; cin >> n >> tot;
    vector<int> books(n);
    for (int i = 0; i < n; i++) cin >> books[i];

    // vector<vector<int>> dp(n + 1, vector<int>(tot + 1));
    // dp[seen_i_books][spent_x_coins] -> max pages
    // dp[0][0] = 0;

    vector<int> dp(tot + 1);
    // dp[spent_x_coins] -> max pages

    for (int i = 1, __best = 0; i <= n; i++) {
        int pages, cost;
        cin >> pages; cost = books[i - 1];
        __best += cost;
        for (int coins = min(tot, __best); coins >= 1; coins--) {
            ckmax(dp[coins], dp[coins - 1]);
            if (coins >= cost) ckmax(dp[coins], dp[coins - cost] + pages);
        }
    }

    cout << dp[tot] << '\n';

    return 0;
}
