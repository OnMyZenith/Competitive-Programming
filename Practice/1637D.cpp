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

const int N = 1e4 + 7;

bitset<N> dp;

void solve() {
    int n; cin >> n;
    vector<int> a(n), b(n);
    int ans = 0;
    for (auto &u : a) {
        cin >> u;
        ans += u * u;
    }
    for (auto &u : b) {
        cin >> u;
        ans += u * u;
    }
    
    dp.reset(); dp[0] = 1;
    for (int i = 0; i < n; i++) {
        dp = (dp << a[i]) | (dp << b[i]);
    }
    
    int sum = accumulate(a.begin(), a.end(), 0) + accumulate(b.begin(), b.end(), 0);
    int x = sum / 2;
    while(!dp[x]) x--;
    ans *= (n - 2);
    cout << ans + x * x + (sum - x) * (sum - x) << '\n';
}

int main() {
    vamos;

    int TT = 1;
    cin >> TT;
    while(TT--) {
        solve();
    }

    return 0;
}