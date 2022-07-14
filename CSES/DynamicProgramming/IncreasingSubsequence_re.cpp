/* Author: OnMyZenith - https://github.com/OnMyZenith */
#include "bits/stdc++.h"
using namespace std;
using ll = long long;

#ifdef asr_debug
#include "dbg.hpp"
#else
#define dbg(...) 007
#endif

const int inf = 1e9 + 7;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << setprecision(15) << fixed;

    int n;
    cin >> n;

    vector<int> dp(n + 1, inf);
    dp[0] = 0;

    // dp[len] <- smallest number that the sequence of length 'len' ends at;

    while (n--) {
        int x; cin >> x;
        int j = int(lower_bound(dp.begin(), dp.end(), x) - dp.begin());
        dp[j] = min(dp[j], x);
    }
    cout << int(lower_bound(dp.begin(), dp.end(), inf) - dp.begin()) - 1 << '\n';

    return 0;
}
