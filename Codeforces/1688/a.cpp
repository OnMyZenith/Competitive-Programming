/* Author: OnMyZenith - https://github.com/OnMyZenith */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef asr_debug
#include "dbg.hpp"
#else
#define dbg(...) 007
#endif
constexpr int pct(int x) { return __builtin_popcount(x); }                                  // # of bits set
constexpr int log_2(int x) { return x ? (8 * (int)sizeof(x)) - 1 - __builtin_clz(x) : -1; } // Floor of log_2(x); index of highest 1-bit
constexpr int log_2_ceil(int x) { return log_2(x) + int(__builtin_popcount(x) != 1); }      // Ceil of log_2(x);
constexpr int contained_pow_2(int x) { return x > 0 ? 1 << log_2_ceil(x) : 0; }             // 16->16, 13->16, (x<=0)->0; Smallest number that's a power of 2, that's not smaller than x


void solve() {
    int x; cin >> x;
    int y = 0;
    bool f = 0, s = 0;
    for (int i = 0; i < 31; i++) {
        if(!f && ((x >> i) & 1)) {
            y |= 1 << i;
            f  = 1;
        }
        
        if(!s && !((x >> i) & 1) && pct(x) == 1) {
            y |= 1 << i;
            s  = 1;
        }

    }
    cout << y << '\n';


}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << setprecision(15) << fixed;

    int TT = 1;
    cin >> TT;
    while(TT--) {
        solve();
    }

    return 0;
}