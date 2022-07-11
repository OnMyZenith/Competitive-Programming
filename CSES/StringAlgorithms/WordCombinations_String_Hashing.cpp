/* Author: OnMyZenith - https://github.com/OnMyZenith */
#include "bits/stdc++.h"
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
#else
#define dbg(...) 007
#endif

const int MOD = 1e9 + 007; // 998244353;

int modpow(ll n, uint64_t p) {
    ll res = 1;
    while (p > 0) {
        if (p & 1) res *= n, res %= MOD;
        n *= n;
        n %= MOD;
        p >>= 1;
    }
    return res % MOD;
}

int modinv(int n) {
    return modpow(n, MOD - 2);
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << setprecision(15) << fixed;

    string s;
    int k;
    cin >> s >> k;

    // dbg(modpow(2, 10));

    int p = 31, n = (int)s.length();
    vector<ll> h(n + 1), ppow(n);
    ppow[0] = 1;
    for (int i = 1; i < n; i++) {
        ppow[i] = ppow[i - 1] * p % MOD;
    }
    for (int i = 0; i < n; i++) {
        h[i + 1] = (h[i] + (s[i] - 'a' + 1) * ppow[i]) % MOD;
    }
    vector<string> a(k);
    vector<pair<ll, int>> id;
    for (auto &str : a) {
        cin >> str;
        if ((int)str.size() > n) continue;
        ll val = 0;
        for (int i = 0; i < (int)str.size(); i++)
            val = (val + (str[i] - 'a' + 1) * ppow[i]) % MOD;

        id.push_back({val, (int)str.size()});
    }
    vector<int> dp(n + 1);

    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (auto [hs, len] : id) {
            if (len > i) continue;
            if (hs * ppow[i - len] % MOD != (h[i] - h[i - len] + MOD) % MOD) continue;
            // if (hs != (h[i] - h[i - len] + MOD) * modinv((int)ppow[i - len]) % MOD) continue;
            dp[i] += dp[i - len];
            if (dp[i] >= MOD) dp[i] -= MOD;
        }
    }
    dbg(dp);
    cout << dp[n] << '\n';
    return 0;
}
