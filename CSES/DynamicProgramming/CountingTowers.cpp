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

template <int MOD, int RT>
struct mint {
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
        long long x;
        cin >> x;
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

const int MOD = 1e9 + 007; // 998244353;
typedef mint<MOD, 5> mi;   // 5 is primitive root for both common mods

// mi fact[(int)1e6];
// bool factorialsPrepared;
// int nCr(int n, int r) {
//     assert(factorialsPrepared);
//     if (r > n) return 0;
//     assert(n > 0 && r >= 0);
//     mi res = fact[n] * inv(fact[n - r]) * inv(fact[r]);
//     return res.v;
// }
// void prepareFact(int n) {
//     fact[0] = 1;
//     for (int i = 1; i <= n; i++) fact[i] = fact[i - 1] * i;
//     factorialsPrepared = true;
// }

void solve() {
    int n;
    cin >> n;

    // dp_prev[joint][state];
    vector<vector<mi>> dp_prev(2, vector<mi>(4));
    dp_prev[1][3] = 1;
    dp_prev[0][3] = 1;
    auto dp_curr = dp_prev;

    {
        dp_curr[0][3] = dp_curr[0][2] = dp_curr[0][1] = dp_curr[0][0] = dp_curr[1][3] = dp_curr[1][0] = 1;
        dp_prev = dp_curr;
    }

    for (int i = 1; i < n; i++) {

        // separate and both closed
        dp_curr[0][3] = dp_prev[0][0] + dp_prev[0][1] + dp_prev[0][2] + dp_prev[0][3] + dp_prev[1][3];
        
        dp_curr[0][2] = dp_prev[0][0] + dp_prev[0][1] + dp_prev[0][2] + dp_prev[0][3] + dp_prev[1][3];
        
        dp_curr[0][1] = dp_prev[0][0] + dp_prev[0][1] + dp_prev[0][2] + dp_prev[0][3] + dp_prev[1][3];
        
        dp_curr[0][0] = dp_prev[0][0] + dp_prev[0][1] + dp_prev[0][2] + dp_prev[0][3] + dp_prev[1][3];

        dp_curr[1][3] = dp_prev[0][3] + dp_prev[1][3] + dp_prev[1][0];

        dp_curr[1][0] = dp_prev[1][3] + dp_prev[1][0] + dp_prev[0][3];

        dp_prev = dp_curr;
    }
    cout << (dp_curr[0][3] + dp_curr[1][3]).v << '\n';
}

int main() {
    vamos;

    vector<int> res(int(1e6 + 7));
    // dp_prev[joint][state];
    vector<vector<mi>> dp_prev(2, vector<mi>(4));
    dp_prev[0][3] = dp_prev[0][2] = dp_prev[0][1] = dp_prev[0][0] = dp_prev[1][3] = dp_prev[1][0] = 1;
    auto dp_curr = dp_prev;

    for (int i = 1; i < 1e6 + 1; i++) {
        res[i] = (dp_curr[0][3] + dp_curr[1][3]).v;
    
        // separate and both closed
        dp_curr[0][3] = dp_prev[0][0] + dp_prev[0][1] + dp_prev[0][2] + dp_prev[0][3] + dp_prev[1][3];
        
        dp_curr[0][2] = dp_prev[0][0] + dp_prev[0][1] + dp_prev[0][2] + dp_prev[0][3] + dp_prev[1][3];
        
        dp_curr[0][1] = dp_prev[0][0] + dp_prev[0][1] + dp_prev[0][2] + dp_prev[0][3] + dp_prev[1][3];
        
        dp_curr[0][0] = dp_prev[0][0] + dp_prev[0][1] + dp_prev[0][2] + dp_prev[0][3] + dp_prev[1][3];

        dp_curr[1][3] = dp_prev[0][3] + dp_prev[1][3] + dp_prev[1][0];

        dp_curr[1][0] = dp_prev[1][3] + dp_prev[1][0] + dp_prev[0][3];

        dp_prev = dp_curr;
    }

    int TT = 1;
    cin >> TT;
    while (TT--) {
        int n; cin >> n;
        cout << res[n] << '\n';
    }

    return 0;
}