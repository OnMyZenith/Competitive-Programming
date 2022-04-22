/* Author: OnMyZenith - https://github.com/OnMyZenith */
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;

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

#define vamos ios_base::sync_with_stdio(false), cin.tie(nullptr), cout << setprecision(15) << fixed;

#define tcT template <class T
#define tcTU tcT, class U
#define tcTUU tcT, class... U

#define f0r(i, n) for (int i = 0; i < (n); ++i)
#define f1r(i, l, r) for (int i = (l); i <= (r); ++i)
#define f0rd(i, n) for (int i = (n); i >= 0; --i)
#define f1rd(i, l, r) for (int i = (l); i >= (r); --i)
#define each(i, a) for (auto &i : a)

// for array type I/O, for other types use INPUT/OUTPUT section
#define ai(a, n) f0r(i, n) cin >> a[i];
#define ain(a, l, r) f1r(i, l, r) cin >> a[i];
#define ao(a, n) f0r(i, n) cout << a[i] << " \n"[i == n - 1];
#define aout(a, l, r) f1r(i, l, r) cout << a[i] << " \n"[i == r];

#define pb push_back
#define eb emplace_back
#define ff first
#define ss second
#define lb lower_bound
#define ub upper_bound
#define ins insert
#define rsz resize
#define ass assign
#define ts to_string
#define nl '\n'

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define sor(v) sort(all(v))
#define soR(v) sort(rall(v))
#define sz(v) ((int)v.size())

tcT > using V = vector<T>;
tcT > using Q = queue<T>;
tcTU > using P = pair<T, U>;
tcT, size_t SZ > using AR = array<T, SZ>;
tcT > using pqdec = std::priority_queue<T>;
tcT > using pqinc = std::priority_queue<T, V<T>, greater<T>>;

using ll = long long;
using db = double;
using ld = long double;
using ull = unsigned long long;
using str = string;

using vs = V<string>;
using vb = V<bool>;

using vi = V<int>;
using vd = V<db>;
using vl = V<ll>;
using vld = V<ld>;

using vvi = V<vi>;
using vvl = V<vl>;
using vvd = V<vd>;
using vvld = V<vld>;

using pi = P<int, int>;
using pl = P<ll, ll>;
using pd = P<db, db>;
using pld = P<ld, ld>;

using vpi = V<pi>;
using vpl = V<pl>;
using vpd = V<pd>;
using vpld = V<pld>;

// EasyIO
#ifndef ___EASY_IO
#define ___EASY_IO 1

// INPUT
template <class T, class U> void re(pair<T, U> &p);
template <class T> void re(vector<T> &v);
template <class T, size_t SZ> void re(array<T, SZ> &a);

template <class T>
void re(T &x) { cin >> x; }
void re(double &d) {
    string t;
    re(t);
    d = stod(t);
}
void re(long double &d) {
    string t;
    re(t);
    d = stold(t);
}
template <class T, class... U>
void re(T &t, U &...u) {
    re(t);
    re(u...);
}
template <class T, class U>
void re(pair<T, U> &p) { re(p.ff, p.ss); }
template <class T>
void re(vector<T> &x) { for (auto &a : x) re(a); }
template <class T, size_t SZ>
void re(array<T, SZ> &x) { for (auto &a : x) re(a); }
template <class T>
void rv(int n, vector<T> &x) {
    x.resize(n);
    re(x);
}

// TO_STRING
string to_string(char c) { return string(1, c); }
string to_string(const char *s) { return (string)s; }
string to_string(string s) { return s; }
string to_string(bool b) {
#ifdef asr_debug
    return b ? "true" : "false";
#else
    return to_string((int)b);
#endif
}
string to_string(vector<bool> v) {
    string res = "{";
    for (int i = 0; i < int(size(v)); i++)
        res += char('0' + v[i]);
    res += "}";
    return res;
}
template <size_t SZ>
string to_string(bitset<SZ> b) {
    string res = "";
    for (int i = 0; i < SZ; i++)
        res += char('0' + b[i]);
    return res;
}
template <class T, class U>
string to_string(pair<T, U> p);
template <class T>
string to_string(T v) { // containers with begin(), end()
#ifdef asr_debug
    bool fst = 1;
    string res = "{";
    for (const auto &x : v) {
        if (!fst) res += ", ";
        fst = 0;
        res += to_string(x);
    }
    res += "}";
    return res;
#else
    bool fst = 1;
    string res = "";
    for (const auto &x : v) {
        if (!fst) res += " ";
        fst = 0;
        res += to_string(x);
    }
    return res;
#endif
}

template <class T, class U>
string to_string(pair<T, U> p) {
#ifdef asr_debug
    return "(" + to_string(p.ff) + ", " + to_string(p.ss) + ")";
#else
    return to_string(p.ff) + " " + to_string(p.ss);
#endif
}

// OUTPUT
template <class T>
void pr(T x) { cout << to_string(x); }
template <class T, class... U>
void pr(const T &t, const U &...u) { // print without spaces
    pr(t);
    pr(u...);
}

void ps() { pr("\n"); }
template <class T, class... U>
void ps(const T &t, const U &...u) { // print with spaces, with newline in the end
    pr(t);
    if (sizeof...(u)) pr(" ");
    ps(u...);
}
#endif // ___EASY_IO


#ifdef asr_debug
#include "dbg.hpp"
#else
#define dbg(...) 007
#endif

tcT > bool ckmin(T &x, const T &y) { return (y < x) ? (x = y, 1) : 0; }
tcT > bool ckmax(T &x, const T &y) { return (y > x) ? (x = y, 1) : 0; }
tcT > T cdiv(T &a, T &b) { return a / b + ((a ^ b) > 0 && a % b); }
tcT > T fdiv(T &a, T &b) { return a / b - ((a ^ b) < 0 && a % b); }
tcT > int lwb(V<T> &a, const T &b) { return int(lb(all(a), b) - begin(a)); }
tcT > int upb(V<T> &a, const T &b) { return int(ub(all(a), b) - begin(a)); }
tcT > void remDup(V<T> &v) { sort(all(v)), v.erase(unique(all(v)), end(v)); }
tcT > T pow(T a, ll b) { T r = 1; while (b) { if (b & 1) r *= a; b >>= 1; a *= a; } return r; }

//these are checked at (1 + eps == 1) on CF, accuracy gets better near zero
const float epsf = 1e-7F;
const long double epsld = 1e-19L;
const double epsd = 2e-16;
const long double PI = 3.14159265358979323846L;
const long long lINF = 2e18L + 007;
const int iINF = 2e9 + 007;
// const int MOD = 1e9 + 007; // 998244353;
mt19937 rng((unsigned int)std::chrono::steady_clock::now().time_since_epoch().count()); // mt19937 rng(61378913);
// e.g. shuffle(permutation.begin(), permutation.end(), rng);

const int __ = 1e6 + 007;  // 1e6 + 007 => int arr =   4 MB, ll arr =   8 MB
const int _ = 2e5 + 007;   // 2e5 + 007 => int arr = 0.8 MB, ll arr = 1.6 MB
const int dr[4] = {-1, 0, 1, 0}, dc[4] = {0, 1, 0, -1}; // URDL
const char dir[4] = {'U', 'R', 'D', 'L'};

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

// constexpr int pct(int x) { return __builtin_popcount(x); }                                  // # of bits set
// constexpr int log_2(int x) { return x ? (8 * (int)sizeof(x)) - 1 - __builtin_clz(x) : -1; } // Floor of log_2(x); index of highest 1-bit
// constexpr int next_pow_2(int x) { return x > 0 ? 1 << log_2(2 * x - 1) : 0; }               // 16->16, 13->16, (x<=0)->0
// constexpr int log_2_ceil(int x) { return log_2(x) + int(__builtin_popcount(x) != 1); }      // Ceil of log_2(x);

long long compute_hash(string const& s) {
    const int p = 31;
    const int m = 1e9 + 9;
    long long hash_value = 0;
    long long p_pow = 1;
    for (char c : s) {
        hash_value = (hash_value + (c - 'a' + 1) * p_pow) % m;
        p_pow = (p_pow * p) % m;
    }
    return hash_value;
}


int main() {
    int n; cin >> n;
    string s; cin >> s;

    vector<bool> a(1 << n), sym(1 << n, 1);
    for (int i = 1; i < (1 << n); i++) a[i] = s[i - 1] == 'A';

    vector<ll> h(1 << n);
    for (int i = (1 << (n)) - 1; i >= 1; i--) {
        bool f = 1;
        
    }


    mi ans = 1;
    for (int i = (1 << (n - 1)) - 1; i >= 1; i--) {
        bool f = 1;
        
    }
    ps(ans);
    return 0;
}