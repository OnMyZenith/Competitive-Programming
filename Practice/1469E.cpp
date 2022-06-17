/* Author: OnMyZenith - https://github.com/OnMyZenith */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#ifndef asr_debug
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
// #pragma GCC optimize("Ofast")
// Can casuse floating point errors, assumes associativeness for instance

#pragma GCC target("avx2")
#pragma GCC target("popcnt,lzcnt,bmi,bmi2,tune=native")
// #pragma GCC target("avx,fma")
// #pragma GCC target("sse4.2,fma")
// run custom tests with stuff like assert(__builtin_cpu_supports("avx2"))
// or use avx instead of sse4.2, leave fma in as it was covered in avx2
#endif

#ifdef asr_debug
#include "dbg.hpp"
const int N = 1e6 + 7;
#else
#define dbg(...) 007
const int N = 1e6 + 7;
#endif

constexpr int pct(int x) { return __builtin_popcount(x); }                                      // # of bits set
constexpr int log_2(int x) { return x > 0 ? (8 * (int)sizeof(x)) - 1 - __builtin_clz(x) : -1; } // Floor of log_2(x); index of highest 1-bit
constexpr int log_2_ceil(int x) { return log_2(x) + int(pct(x) != 1); }                         // Ceil of log_2(x);
constexpr int enveloping_pow_2(int x) { return x > 0 ? 1 << log_2_ceil(x) : 0; }                // 16->16, 13->16, (x<=0)->0; Smallest number that's a power of 2, that's not smaller than x

bitset<N> pre_taken;
bitset<N> taken;
bitset<N> s;


void solve() {
    int n, k; cin >> n >> k;
{
    char c;
    for (int i = 0; i < n; i++) {
        cin >> c; s[i] = c == '1';
    }
}
    int x = enveloping_pow_2(n - k + 1);

    for (int i = 0; i < n - k + 1; i++) pre_taken.reset(i);

    string pre;
    if (k - x > 0) {
        pre += string(k - x, '0');
        // int start = 0, end = (k - x - 1) + (n - k + 1);
        for (int i = 0; i < n - x; i++) {
            
        }
        for (int str_pos = 0; str_pos < k - x; str_pos++) {
            for (int str_no = 0; str_no < n - k + 1; str_no++) {
                if (pre_taken[str_no]) continue;
                pre_taken[str_no] = !s[str_pos + str_no];
            }
        }
    }
    // dbg(pre, pre_taken, x, k);
    x = min(k, x);
    for (int rmask = (1 << x) - 1, mask; rmask >= 0; rmask--) {
        mask = (1 << x) - 1 - rmask;
        for (int i = 0; i < n - k + 1; i++) {
            taken[i] = pre_taken[i];
        }
        // dbg(s);
        for (int j = 0; j < x && j + max(k - x, 0) < k; j++) {
            int start = j + max(k - x, 0);
            for (int i = 0; i < n - k + 1; i++) {
                // dbg(taken, start, j, int(1 & (mask >> j)), int(s[start + i]));
                taken[i] = taken[i] | (s[start + i] == (1 & (mask >> j)));
            }
            // dbg(taken);
        }
        bool pass = 1;
        for (int i = 0; i < n - k + 1; i++) {
            pass &= taken[i];
        }
        // dbg(taken, mask, rmask);
        if(pass) {
            cout << "YES\n";
            string res = bitset<22>(mask).to_string();
            reverse(res.begin(), res.end());
            cout << pre + res.substr(0, x) << '\n';
            return;
        }
    }
    cout << "NO\n";
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
