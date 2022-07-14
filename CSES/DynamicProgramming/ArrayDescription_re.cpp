/* Author: OnMyZenith - https://github.com/OnMyZenith */
#include "bits/stdc++.h"
using namespace std;
using ll = long long;

#ifdef asr_debug
#include "dbg.hpp"
#else
#define dbg(...) 007
#endif

const int MOD = 1e9 + 7;
const int M = 100 + 7;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << setprecision(15) << fixed;

    int n, m; cin >> n >> m;

    vector<int> dp_prev(m + 2), dp_curr(m + 2);

    int x; cin >> x;
    if (x) dp_prev[x] = 1;
    else 
        for (int i = 1; i <= m; i++)
            dp_prev[i] = 1;

    for (int i = 2; i <= n; i++) {
        cin >> x;
        if (x) {
            dp_curr[x] = ((ll)dp_prev[x - 1] + dp_prev[x + 1] + dp_prev[x]) % MOD;

            for (int j = 1; j <= m; j++)
                if (x != j)
                    dp_curr[j] = 0;

        } else {
            for (int j = 1; j <= m; j++) {
                dp_curr[j] = ((ll)dp_prev[j - 1] + dp_prev[j + 1] + dp_prev[j]) % MOD;
            }
        }
        swap(dp_prev, dp_curr);
    }

    cout << (x ? dp_prev[x] : accumulate(dp_prev.begin(), dp_prev.end(), 0ll) % MOD) << '\n';
    return 0;
}
