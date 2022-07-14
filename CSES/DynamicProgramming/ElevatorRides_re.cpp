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

    int n, x;
    cin >> n >> x;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<array<int, 2>> dp(1 << n, {n + 1, 0});
    dp[0] = {1, -x};

    for (int mask = 1; mask < 1 << n; mask++) {
        for (int j = 0; j < n; j++) {
            if (mask >> j & 1) {
                auto prev = dp[mask ^ (1 << j)];
                prev[1] = -prev[1];
                if (prev[1] >= a[j]) {
                    ckmin(dp[mask], {prev[0], -(prev[1] - a[j])});
                } else {
                    ckmin(dp[mask], {prev[0] + 1, -max(x - a[j], prev[1])});
                }
            }
        }
    }
    cout << dp[(1 << n) - 1][0] << '\n';
    return 0;
}
