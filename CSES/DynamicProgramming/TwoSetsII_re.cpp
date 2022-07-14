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

template <class T>
T pow(T a, uint64_t p) {
    T ret = 1;
    while (p) {
        if (p & 1) ret *= a;
        p >>= 1;
        a *= a;
    }
    return ret;
}

int modpow(int a, uint64_t p) {
    int ret = 1;
    while (p) {
        if (p & 1) ret = (ll)a * ret % MOD;
        p >>= 1;
        a = (ll)a * a % MOD;
    }
    return ret;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << setprecision(15) << fixed;

    int n;
    cin >> n;
    int x = n * (n + 1) / 4;

    if ((n * (n + 1) / 2) & 1) {
        cout << "0\n";
        return 0;
    }

    vector<int> dp(x + 1);
    dp[0] = 1;

    for (int val = 1; val <= n; val++) {
        for (int curr = x; curr >= val; curr--) {
            dp[curr] += dp[curr - val];
            if (dp[curr] >= MOD) dp[curr] -= MOD;
        }
    }
    cout << (ll)dp[x] * modpow(2, MOD - 2) % MOD << '\n';
    return 0;
}
