/* Author: OnMyZenith - https://github.com/OnMyZenith */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef asr_debug
#include "dbg.hpp"
#else
#define dbg(...) 007
#endif

constexpr int pct(ll x) { return __builtin_popcountll(x); }                                      // # of bits set
// Check result against SIZE of vector
template <class T> int lwbf(vector<T> &a, const T &b) { return int(lower_bound(a.begin(), a.end(), b) - begin(a)); }
constexpr int pct(int x) { return __builtin_popcount(x); }                                      // # of bits set
constexpr int log_2(int x) { return x > 0 ? (8 * (int)sizeof(x)) - 1 - __builtin_clz(x) : -1; } // Floor of log_2(x); index of highest 1-bit
constexpr int log_2_ceil(int x) { return log_2(x) + int(pct(x) != 1); }                         // Ceil of log_2(x);
constexpr int enveloping_pow_2(int x) { return x > 0 ? 1 << log_2_ceil(x) : 0; }                // 16->16, 13->16, (x<=0)->0; Smallest number that's a power of 2, that's not smaller than x

// Check result <= hi
template <class T, class U> T ft(T lo, T hi, U f) {
    ++hi, assert(lo <= hi);
    while (lo < hi) {
        T mid = lo + (hi - lo) / 2;
        f(mid) ? hi = mid : lo = mid + 1;
    }
    return lo;
}

void solve() {
    ll n, k; cin >> n >> k;

    vector<ll> s;
    for (int bit = 0; bit <= 31; bit++) {
        s.push_back((1ll << bit)  - 1);
    }
    ll ans = 0;
    while (n) {
        if(k <= n) {
            ans += k;
            break;
        }
        if(n == 1 || k == 1 || k == 0) {
            ans += pct(k);
            break;
        }
        ll x = (k + n - 1) / n;
        ll id = lwbf(s, x);
        if(id <= 1) {
            ans += k;
            break;
        }
        ll q = ft(0ll, n - 1, [&](ll mid) {
            return lwbf(s, ((k - mid * s[id] + n - mid - 1) / (n - mid))) < lwbf(s, (k + n - 1) / n);
        });
        dbg(q);
        if(q == n) {
            ans += k / s[id] * pct(s[id]);
            ans += pct(k % s[id]);
            break;
        }
        dbg(k, s[id], id, n, q);
        k -= q * s[id];
        ans += q * pct(s[id]);
        n -= q;
    }
    cout << ans << '\n';
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