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

#define vamos ios_base::sync_with_stdio(false);
#define fix(prec) cout << setprecision(prec) << fixed;

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

// INPUT
tcT > void re(complex<T> &c);
tcTU > void re(P<T, U> &p);
tcT > void re(V<T> &v);
tcT, size_t SZ > void re(AR<T, SZ> &a);

tcT > void re(T &x) { cin >> x; }
void re(db &d) {
    str t;
    re(t);
    d = stod(t);
}
void re(ld &d) {
    str t;
    re(t);
    d = stold(t);
}
tcTUU > void re(T &t, U &...u) {
    re(t);
    re(u...);
}
tcT > void re(complex<T> &c) {
    T a, b;
    re(a, b);
    c = {a, b};
}
tcTU > void re(P<T, U> &p) { re(p.ff, p.ss); }
tcT > void re(V<T> &x) { each(a, x) re(a); }
tcT, size_t SZ > void re(AR<T, SZ> &x) { each(a, x) re(a); }
tcT > void rv(int n, V<T> &x) {
    x.rsz(n);
    re(x);
}

// TO_STRING
str ts(char c) { return str(1, c); }
str ts(const char *s) { return (str)s; }
str ts(str s) { return s; }
str ts(bool b) {
#ifdef asr_debug
    return b ? "true" : "false";
#else
    return ts((int)b);
#endif
}
tcT > str ts(complex<T> c) {
    stringstream ss;
    ss << c;
    return ss.str();
}
str ts(V<bool> v) {
    str res = "{";
    f0r(i, sz(v))
        res += char('0' + v[i]);
    res += "}";
    return res;
}
template <size_t SZ>
str ts(bitset<SZ> b) {
    str res = "";
    f0r(i, SZ)
        res += char('0' + b[i]);
    return res;
}
tcTU > str ts(P<T, U> p);
tcT > str ts(T v) { // containers with begin(), end()
#ifdef asr_debug
    bool fst = 1;
    str res = "{";
    for (const auto &x : v) {
        if (!fst) res += ", ";
        fst = 0;
        res += ts(x);
    }
    res += "}";
    return res;
#else
    bool fst = 1;
    str res = "";
    for (const auto &x : v) {
        if (!fst) res += " ";
        fst = 0;
        res += ts(x);
    }
    return res;
#endif
}

tcTU > str ts(P<T, U> p) {
#ifdef asr_debug
    return "(" + ts(p.ff) + ", " + ts(p.ss) + ")";
#else
    return ts(p.ff) + " " + ts(p.ss);
#endif
}

// OUTPUT
tcT > void pr(T x) { cout << ts(x); }
tcTUU > void pr(const T &t, const U &...u) { // print without spaces
    pr(t);
    pr(u...);
}

void ps() { pr("\n"); }
tcTUU > void ps(const T &t, const U &...u) { // print with spaces, with newline in the end
    pr(t);
    if (sizeof...(u)) pr(" ");
    ps(u...);
}

#ifdef asr_debug
#include "dbg.hpp"
#else
#define dbg(...) 007
#define chk(...) 007
#endif

tcT > bool ckmin(T &x, const T &y) { return (y < x) ? (x = y, 1) : 0; }
tcT > bool ckmax(T &x, const T &y) { return (y > x) ? (x = y, 1) : 0; }
tcT > T cdiv(T &a, T &b) { return a / b + ((a ^ b) > 0 && a % b); }
tcT > T fdiv(T &a, T &b) { return a / b - ((a ^ b) < 0 && a % b); }
tcT > int lwb(V<T> &a, const T &b) { return int(lb(all(a), b) - bg(a)); }
tcT > int upb(V<T> &a, const T &b) { return int(ub(all(a), b) - bg(a)); }
tcT > void remDup(V<T> &v) { sort(all(v)), v.erase(unique(all(v)), end(v)); }
tcT > T pow(T a, ll b) { T r = 1; while (b) { if (b & 1) r *= a; b >>= 1; a *= a; } return r; }

//these are checked at (1 + eps == 1) on CF, accuracy gets better near zero
const float epsf = 1e-7F;
const long double epsld = 1e-19L;
const double epsd = 2e-16;
const long double PI = 3.14159265358979323846L;
const long long lINF = 2e18L + 007;
const int iINF = 2e9 + 007;
mt19937 rng((unsigned int)std::chrono::steady_clock::now().time_since_epoch().count()); // mt19937 rng(61378913);
// e.g. shuffle(permutation.begin(), permutation.end(), rng);

const int __ = 1e6 + 007;  // 1e6 + 007 => int arr =   4 MB, ll arr =   8 MB
const int _ = 2e5 + 007;   // 2e5 + 007 => int arr = 0.8 MB, ll arr = 1.6 MB
const int dr[4] = {-1, 0, 1, 0}, dc[4] = {0, 1, 0, -1}; // URDL
const char dir[4] = {'U', 'R', 'D', 'L'};

struct splitmix64_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

tcTU, typename Hash = splitmix64_hash> using hash_map = gp_hash_table<T, U, Hash>;
tcT, typename Hash = splitmix64_hash> using hash_set = hash_map<T, null_type, Hash>;
constexpr int pct(int x) { return __builtin_popcount(x); }                                  // # of bits set
constexpr int log_2(int x) { return x ? (8 * (int)sizeof(x)) - 1 - __builtin_clz(x) : -1; } // Floor of log_2(x); index of highest 1-bit
constexpr int next_pow_2(int x) { return x > 0 ? 1 << log_2(2 * x - 1) : 0; }               // 16->16, 13->16, (x<=0)->0
constexpr int log_2_ceil(int x) { return log_2(x) + int(__builtin_popcount(x) != 1); }      // Ceil of log_2(x);

tcT > struct segtree {
    // ALL INPUT FROM THE USER IS 0 BASED.
    int SZ;
    V<T> v;

    static constexpr T NEUTRAL_VAL = 0; // Change this
    T f(T a, T b) { return gcd(a, b); };   // Change this

    // v i.e. the tree is indexed 1 based & a i.e. input data is indexed 0 based.
    void build(V<T> &a) {
        SZ = 2 * next_pow_2(sz(a));
        v.ass(SZ, NEUTRAL_VAL);
        f0r(i, sz(a)) v[SZ / 2 + i] = a[i];
        f1rd(i, SZ / 2 - 1, 1) v[i] = f(v[2 * i], v[2 * i + 1]);
    }

    // idx is 0 based
    void update(int idx, T x) {
        int i = SZ / 2 + idx;
        v[i] = x;
        for (i /= 2; i > 0; i /= 2)
            v[i] = f(v[2 * i], v[2 * i + 1]);
    }

    // ql, qr, lx and rx are 0 based, node is 1 based
    T q(int ql, int qr, int lx, int rx, int node) {
        if (ql <= lx && rx <= qr) return v[node];
        if (qr < lx || rx < ql) return NEUTRAL_VAL;
        return f(q(ql, qr, lx, (lx + rx) / 2, node * 2), q(ql, qr, (lx + rx) / 2 + 1, rx, node * 2 + 1));
    }

    // ql and qr are inclusive and 0 based
    T q(int ql, int qr) { return q(ql, qr, 0, SZ / 2 - 1, 1); }

    void printWillTLE() {
#ifdef asr_debug
        int nodes = 1, spaces = SZ, idx = 1;
        while (idx < SZ) {
            f0r(j, nodes) {
                cout << setw(j ? 2 * spaces : spaces);
                if (v[idx] != NEUTRAL_VAL) pr(v[idx]);
                else
                    pr('_');
                idx++;
            }
            cout << '\n';
            nodes *= 2;
            spaces /= 2;
        }
        f0r(k, 2 * SZ) cout << "-\n"[k == 2 * SZ - 1];
#else
        return;
#endif
    }
};

const int MOD = 1e9 + 007; // 998244353;
vi a;
void solve() {
    int n; re(n); int ans = 0; rv(n,a);
    segtree<int> s; s.build(a);
    for (int i = 0; i < n; i++){
        int l = 1, r = i+1;
        while (l <= r) {
            int len = (l + r) / 2;
            int g = s.q(i-len+1, i);
            if (g == (len)) {
                s.update(i, MOD);
                ans++;
                break;
            }
            if (g < (len)) r = len - 1;
            else l = len + 1;
        }
        cout << ans << " \n"[i == n - 1];
    }
}

int main() {

#ifdef asr_time
    auto begin = chrono::high_resolution_clock::now();
#endif

    vamos;

    // #ifndef asr_debug
    cin.tie(nullptr);
    // #endif

    fix(15);
    // prepareFact(_);
    int TT = 1;
    // cin >> TT;
    f1r(TC, 1, TT)
        solve();

#ifdef asr_time
    auto end = chrono::high_resolution_clock::now();
    cout << setprecision(2) << fixed;
    cout << "Execution time: " << chrono::duration_cast<chrono::duration<double>>(end - begin).count() * 1000 << " ms" << endl;
#endif

    return 0;
}