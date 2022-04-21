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


constexpr int pct(int x) { return __builtin_popcount(x); }                                  // # of bits set
constexpr int log_2(int x) { return x ? (8 * (int)sizeof(x)) - 1 - __builtin_clz(x) : -1; } // Floor of log_2(x); index of highest 1-bit
constexpr int next_pow_2(int x) { return x > 0 ? 1 << log_2(2 * x - 1) : 0; }               // 16->16, 13->16, (x<=0)->0
constexpr int log_2_ceil(int x) { return log_2(x) + int(__builtin_popcount(x) != 1); }      // Ceil of log_2(x);


void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n), cnt(31);
    // vector<vector<int>> cnt(n, vector<int> (31))
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        for (int j = 0; j < 31; j++) {
            cnt[j] += (a[i] >> j) & 1;
        }
    }
    ll ans = 0;
    for (int j = 30; j >= 0; j--) {
        if(n - cnt[j] <= k) k -= n - cnt[j], ans |= 1 << j;
    }
    cout << ans << '\n';



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