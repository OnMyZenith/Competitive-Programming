/* Author: OnMyZenith - https://github.com/OnMyZenith */
#include "bits/stdc++.h"
using namespace std;
using ll = long long;

#ifdef asr_debug
#include "dbg.hpp"
const int N = 6;
#else
const int N = 2e5 + 7;
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


mi fact[(int)1e6];
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

int s[N], t[N];
int cnts[N];

const int mxC = N * 2;
int ft[mxC + 2];
void upd(int i, int x) {
    for (++i; i <= mxC + 1; i += i & -i)
        ft[i] += x;
}

int qry(int i) {
    int r = 0;
    for (; i; i -= i & -i)
        r += ft[i];
    return r;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << setprecision(15) << fixed;
    prepareFact(2e5 + 7);

    int n, m; cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> s[i], cnts[s[i]]++;
    for (int i = 0; i < m; i++) cin >> t[i];

    mi ans = 0, tot = fact[n];
    for (int i = 0; i < N; i++) {
        upd(i, cnts[i]);
        tot /= mi(fact[cnts[i]]);
    }

    for (int i = 0; i < m && i <= n; i++) {
        int smaller = qry(t[i]);
        if (n - i > 0) ans += tot * smaller / (n - i);
        else if (tot.v > 0) ++ans;
        tot *= qry(t[i] + 1) - qry(t[i]);
        if (n - i > 0) tot /= n - i;
        upd(t[i], -1);
    }
    cout << ans.v << '\n';


    return 0;
}