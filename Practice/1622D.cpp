/* Author: OnMyZenith - https://github.com/OnMyZenith */
#include "bits/stdc++.h"
using namespace std;
using ll = long long;

#ifdef asr_debug
#include "dbg.hpp"
#else
#define dbg(...) 007
#endif

template <int MOD, int RT> struct mint {
    static const int mod = MOD;
    static constexpr mint rt() { return RT; } // primitive root for FFT
    int v;
    explicit operator int() const { return v; } // explicit -> don't silently convert to int
    mint() { v = 0; }
    mint(long long _v) {
        v = int((-MOD < _v && _v < MOD) ? _v : _v % MOD);
        if (v < 0) v += MOD;
    }
    friend bool operator==(const mint &a, const mint &b) { return a.v == b.v; }
    friend bool operator!=(const mint &a, const mint &b) { return !(a == b); }
    friend bool operator<(const mint &a, const mint &b) { return a.v < b.v; }
    friend void re(mint &a) {
        long long x; cin >> x;
        a = mint(x);
    }
    friend string to_string(mint a) { return to_string(a.v); }

    mint &operator+=(const mint &m) {
        if ((v += m.v) >= MOD) v -= MOD;
        return *this;
    }
    mint &operator-=(const mint &m) {
        if ((v -= m.v) < 0) v += MOD;
        return *this;
    }
    mint &operator*=(const mint &m) {
        #pragma GCC diagnostic push
        #pragma GCC diagnostic ignored "-Wconversion"
        v = (long long)v * m.v % MOD;
        #pragma GCC diagnostic pop
        return *this;
    }
    mint &operator/=(const mint &m) { return (*this) *= inv(m); }
    friend mint pow(mint a, long long p) {
        mint ans = 1;
        assert(p >= 0);
        for (; p; p /= 2, a *= a)
            if (p & 1) ans *= a;
        return ans;
    }
    friend mint inv(const mint &a) {
        assert(a.v != 0);
        return pow(a, MOD - 2);
    }

    mint operator-() const { return mint(-v); }
    mint &operator++() { return *this += 1; }
    mint &operator--() { return *this -= 1; }
    friend mint operator+(mint a, const mint &b) { return a += b; }
    friend mint operator-(mint a, const mint &b) { return a -= b; }
    friend mint operator*(mint a, const mint &b) { return a *= b; }
    friend mint operator/(mint a, const mint &b) { return a /= b; }
};

const int MOD = 998244353;
// const int MOD = 1e9 + 007;
typedef mint<MOD, 5> mi;   // 5 is primitive root for both common mods


mi fact[(int)1e4];
bool factorialsPrepared;
int nCr(int n, int r) {
    assert(factorialsPrepared);
    if (r > n) return 0;
    assert(n > 0 && r >= 0);
    mi res = fact[n] * inv(fact[n - r]) * inv(fact[r]);
    return res.v;
}
void prepareFact(int n) {
    fact[0] = 1;
    for (int i = 1; i <= n; i++) fact[i] = fact[i - 1] * i;
    factorialsPrepared = true;
}


int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << setprecision(15) << fixed;
    prepareFact(5007);
    int n, K; cin >> n >> K;
    string str; cin >> str;

    auto calc = [&](const string &s, int k) -> mi {
        if (k == 0) return count(s.begin(), s.end(), '1') + 1;
        dbg(s);
        mi res = 0;
        for (int i = 0; i < (int)s.size();) {
            int cnt_k = 0, len = 0, start = -1;
            for (int j = i; j < (int)s.size() && cnt_k <= k; j++, len++) {
                cnt_k += s[j] == '1';
                if (cnt_k == 1 && start == -1) start = j + 1;
            }
            if (cnt_k == k) {
                dbg(len, start, k);
                res += nCr(len, k);
                break;
            } else {
                i = start;
                len--;
                dbg(len, start, k);
                res += nCr(len, k);
            }
        }
        return res;
    };
    if (K == 0 || count(str.begin(), str.end(), '1') < K) {
        cout << "1\n";
    } else if (count(str.begin(), str.end(), '1') == K) {
        cout << nCr(n, K) << '\n';
    } else {
        int l = -1, r = -1;
        for (int i = 0; i < n; i++) {
            if (str[i] == '1') {
                if (l == -1) l = i;
                else r = i;
            }
        }
        dbg(str, l, r);
        cout << (calc(str, K) - calc(str.substr(l + 1, r - (l + 1)), K - 1)).v << '\n';
    }

    return 0;
}