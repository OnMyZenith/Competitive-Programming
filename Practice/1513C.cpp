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

const int MOD = 1e9 + 7;

int cnt(int n, int m) {
    if(m + n < 10) return 1;
    return (cnt(1, m + n - 10) + cnt(0, m + n - 10)) % MOD;
}

void solve() {
    int n, m; cin >> n >> m;

    vector<int> f(10);
    while (n) f[n % 10]++, n /= 10;

    int res = 0;
    for (int i = 0; i < 10; i++) {
        res += (ll) f[i] * cnt(i, m) % MOD;
    }
    cout << res << '\n';

    // int i = 0;
    // while (m--) {
    //     int j = i;
    //     i--;
    //     if (i < 0) i += 10;
    //     f[j] += f[i];
    //     if (f[j] >= MOD) f[j] -= MOD;
    // }
    // cout << accumulate(f.begin(), f.end(), 0LL) % MOD << '\n';
}

int main() {
    vamos;

    // vector<vector<int>> f(2e5 + 7, vector<int>(10));

    // for (int i = 0; i < 10; i++) {
        
    // }

    int TT = 1;
    cin >> TT;
    while (TT--) {
        solve();
    }

    return 0;
}