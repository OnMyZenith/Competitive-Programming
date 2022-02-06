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


int main() {
    vamos;

    int n; cin >> n;
    vector<long double> a(n);
    for (auto &u : a) {
        cin >> u;
    }
    vector<long double> dp(n+1);        // dp[heads]
    dp[0] = 1;

    for (int i = 0; i < n; i++) {
        for (int heads = i + 1; heads >= 0; heads--) {
            dp[heads] = (((heads ? dp[heads - 1] : 0) * a[i])  + (dp[heads] * (1 - a[i])));
        }
    }
    cout << accumulate(dp.begin() + n / 2 + 1, dp.end(), 0.0L) << '\n';
    return 0;
}