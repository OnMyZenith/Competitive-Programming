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

template <class T> bool ckmin(T &x, const T &y) { return (y < x) ? (x = y, 1) : 0; }
template <class T> bool ckmax(T &x, const T &y) { return (y > x) ? (x = y, 1) : 0; }

constexpr int pct(ll x) { return __builtin_popcountll(x); }                                  // # of bits set
constexpr int log_2(int x) { return x ? (8 * (int)sizeof(x)) - 1 - __builtin_clz(x) : -1; } // Floor of log_2(x); index of highest 1-bit
constexpr int next_pow_2(int x) { return x > 0 ? 1 << log_2(2 * x - 1) : 0; }               // 16->16, 13->16, (x<=0)->0
constexpr int log_2_ceil(int x) { return log_2(x) + int(__builtin_popcount(x) != 1); }      // Ceil of log_2(x);


vector<ll> fact(15);

void solve() {
    ll n; cin >> n;
    int best = 40;
    for (int mask = 0; mask < (1 << 13); mask++) {
        ll curr = 0;
        for (int i = 0; i < 13; i++) {
            if((mask >> i) & 1) curr += fact[i];
        }
        if(curr <= n) {
            ckmin(best, pct(n - curr) + pct(mask));
        }
    }
    cout << best << '\n';
}


int main() {
    vamos;

    fact[0] = fact[1] = 1;
    for (int i = 2; i < 15; i++) {
        fact[i] = fact[i - 1] * i;
    }
    fact.erase(fact.begin());
    fact.erase(fact.begin());
    int TT = 1;
    cin >> TT;
    while(TT--) {
        solve();
    }

    return 0;
}