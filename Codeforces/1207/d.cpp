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

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << setprecision(15) << fixed;

    prepareFact(3e5 + 7);
    int n; cin >> n;
    vector<array<int, 2>> s(n);
    for (auto &[x, y] : s) {
        cin >> x >> y;
    }
    mi ans = fact[n];

    mi a0 = 1;
    sort(s.begin(), s.end(), [](array<int, 2> &a, array<int, 2> &b) -> bool {
        if (a[0] != b[0]) return a[0] < b[0];
        return a[1] < b[1];
    });
    bool w = 1;
    for (int i = 0; i < n - 1; i++) w &= s[i][1] <= s[i + 1][1];
    for (int i = 0; i < n;) {
        int cnt = 0;
        for (int j = i; j < n; j++) {
            if (s[i] == s[j]) cnt++;
            else break;
        }
        i += cnt;
        a0 *= fact[cnt];
    }

    mi a1 = 1, a2 = 1;
    sort(s.begin(), s.end(), [](array<int, 2> &a, array<int, 2> &b) -> bool {
        if (a[0] != b[0]) return a[0] < b[0];
        return a[1] < b[1];
    });
    for (int i = 0; i < n;) {
        int cnt = 0;
        for (int j = i; j < n; j++) {
            if (s[i][0] == s[j][0]) cnt++;
            else break;
        }
        i += cnt;
        a1 *= fact[cnt];
    }

    sort(s.begin(), s.end(), [](array<int, 2> &a, array<int, 2> &b) -> bool {
        return a[1] < b[1];
    });
    for (int i = 0; i < n;) {
        int cnt = 0;
        for (int j = i; j < n; j++) {
            if (s[i][1] == s[j][1]) cnt++;
            else break;
        }
        i += cnt;
        a2 *= fact[cnt];
    }
    dbg(ans, a1, a2, a0);
    ans -= a1;
    ans -= a2;
    if (w) ans += a0;
    cout << ans.v << '\n';

    return 0;
}