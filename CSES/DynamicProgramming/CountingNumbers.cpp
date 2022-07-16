/* Author: OnMyZenith - https://github.com/OnMyZenith */
#include "bits/stdc++.h"
using namespace std;
using ll = long long;

#ifdef asr_debug
#include "dbg.hpp"
#else
#define dbg(...) 007
#endif

const int MOD = 1e9 + 007; // 998244353;

int modpow(int a, uint64_t b) {
    int res = 1;
    while (b) {
        if (b & 1) res = (ll)res * a % MOD;
        a = (ll)a * a % MOD;
        b >>= 1;
    }
    return res;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << setprecision(15) << fixed;

    ll a, b;
    cin >> a >> b;
    vector<int> cnt(20);
    for (int i = 0; i < 20; i++) {
        // cnt[i] = (i ? cnt[i - 1] : 0) + modpow(9, i);
        cnt[i] = modpow(9, i);
        if (cnt[i] >= MOD) cnt[i] -= MOD;
    }

    dbg(cnt);

    auto calc = [&](ll x) {
        int res = 0;
        string s = to_string(x);
        reverse(s.begin(), s.end());

        int len = (int)s.length();
        while (len--) {
            int c = s.back() - '0';
            s.pop_back();
            res = (res + (ll)c * cnt[len] % MOD) % MOD;
        }
        return res + 1;
    };

    for (int i = 0; i < 102; i++) {
        cout << i << " :" << calc(i) << '\n';
    }

    dbg(calc(b));
    dbg(calc(a));

    cout << max(calc(b) - calc(a - 1), 0) << '\n';
    return 0;
}
