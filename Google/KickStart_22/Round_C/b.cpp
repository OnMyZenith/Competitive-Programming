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

template <typename T_vector> void ov(const T_vector &v, bool add_one = false, int start = -1, int end = -1) {
    if (start < 0) start = 0;
    if (end < 0) end = int(v.size());

    for (int i = start; i < end; i++)
        cout << v[i] + (add_one ? 1 : 0) << " \n"[i == end - 1];
}

constexpr int pct(int x) { return __builtin_popcount(x); }                                  // # of bits set
constexpr int log_2(int x) { return x ? (8 * (int)sizeof(x)) - 1 - __builtin_clz(x) : -1; } // Floor of log_2(x); index of highest 1-bit
constexpr int next_pow_2(int x) { return x > 0 ? 1 << log_2(2 * x - 1) : 0; }               // 16->16, 13->16, (x<=0)->0
constexpr int log_2_ceil(int x) { return log_2(x) + int(__builtin_popcount(x) != 1); }      // Ceil of log_2(x);


void solve(int _TC) {
    ll n, x, y; cin >> n >> x >> y;
    ll sum = n * (n + 1) / 2;
    if(sum % (x + y)) {
        cout << "Case #" << _TC << ": IMPOSSIBLE\n";
        return;
    }

    vector<ll> al;

    ll a = (sum / (x + y)) * x;

    for (int i = n; i >= 1; i--) {
        if(a >= i) al.push_back(i), a -= i;
    }

    assert(!a);

    // while((1ll << (log_2(a))) < a) {
    //     a -= n;
    //     al.push_back(n--);
    // }

    // dbg(a);
    // for (int i = 30; i >= 0; i--) {
    //     if((a >> i) & 1) a ^= (1 << i), al.push_back(1 << i);
    // }

    // assert(!a);



    cout << "Case #" << _TC << ": POSSIBLE\n";
    cout << (int)al.size() << '\n';
    ov(al);


}

int main() {
    vamos;

    int TT = 1;
    cin >> TT;
    for (int TC = 1; TC <= TT; TC++) {
        solve(TC);
    }

    return 0;
}