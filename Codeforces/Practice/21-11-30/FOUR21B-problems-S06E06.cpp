/* Author: OnMyZenith - https://github.com/OnMyZenith */
#include <bits/extc++.h>
// #include <chrono>
// #include <bits/stdc++.h>
using namespace __gnu_pbds;
using namespace std;

// #pragma GCC optimize("Ofast")
// #pragma GCC target("avx,avx2,fma")

// #pragma GCC optimize ("O3")
// #pragma GCC target ("sse4")

// #pragma GCC optimize ("O3")
// #pragma GCC target ("avx2")

#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma,tune=native")

#define vamos ios_base::sync_with_stdio(false), cin.tie(nullptr);
#define fix(prec) cout << setprecision(prec) << fixed;

#define tcT template <class T
#define tcTU tcT, class U
#define tcTUU tcT, class... U

#define f0r(i, n) for (int i = 0; i < (n); ++i)
#define f1r(i, l, r) for (int i = (l); i <= (r); ++i)
#define f0rd(i, n) for (int i = (n); i >= 0; --i)
#define f1rd(i, l, r) for (int i = (l); i >= (r); --i)
#define each(i, a) for (auto &i : a)

// for pure array I/O, for other types use INPUT/OUTPUT section
#define ai(a, n) f0r(i, n) cin >> a[i];
#define ain(a, l, r) f1r(i, l, r) cin >> a[i];
#define ao(a, n) f0r(i, n) cout << a[i] << " \n"[i == n - 1];
#define aout(a, l, r) f1r(i, l, r) cout << a[i] << " \n"[i == r];

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define ff first
#define ss second
#define lb lower_bound
#define ub upper_bound
#define ins insert
#define ft front()
#define bk back()
#define rsz resize
#define eq equal_range
#define ts to_string
#define nl '\n'

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define sor(v) sort(v.begin(), v.end())
#define soR(v) sort(v.rbegin(), v.rend())
#define sz(v) ((long long)v.size())
#define bg(v) v.begin()

using ll = long long;
using db = double;
using ld = long double;
using ull = unsigned long long;
using str = string;

using vs = vector<string>;
using vb = vector<bool>;

using vi = vector<int>;
using vd = vector<double>;
using vl = vector<long long>;
using vld = vector<long double>;

using vvi = vector<vector<int>>;
using vvl = vector<vector<long long>>;
using vvd = vector<vector<double>>;
using vvld = vector<vector<long double>>;

using pi = pair<int, int>;
using pl = pair<long long, long long>;
using pd = pair<double, double>;
using pld = pair<long double, long double>;

using vpi = vector<pair<int, int>>;
using vpl = vector<pair<long long, long long>>;
using vpd = vector<pair<double, double>>;
using vpld = vector<pair<long double, long double>>;

tcT > using V = vector<T>;
tcT, size_t SZ > using AR = array<T, SZ>;
tcT > using pq = std::priority_queue<T>;
tcT > using pqg = std::priority_queue<T, V<T>, greater<T>>;
tcT > using Q = queue<T>;

tcT > bool ckmin(T &x, const T &y) { return (y < x) ? (x = y, 1) : 0; }
tcT > bool ckmax(T &x, const T &y) { return (y > x) ? (x = y, 1) : 0; }
tcT > T cdiv(T &a, T &b) { return a / b + ((a ^ b) > 0 && a % b); }
tcT > T fdiv(T &a, T &b) { return a / b - ((a ^ b) < 0 && a % b); }
tcT > int lwb(V<T> &a, const T &b) { return int(lb(all(a), b) - bg(a)); }
tcT > int upb(V<T> &a, const T &b) { return int(ub(all(a), b) - bg(a)); }
tcT > void remDup(V<T> &v) { sort(all(v)), v.erase(unique(all(v)), end(v)); }

tcTU > bool erase(T &t, const U &u) {
    auto it = t.find(u);
    if (it == end(t)) return false;
    else
        t.erase(it);
    return true;
}
tcTU > T fstTrue(T lo, T hi, U f) {
    ++hi, assert(lo <= hi);
    while (lo < hi) {
        T mid = lo + (hi - lo) / 2;
        f(mid) ? hi = mid : lo = mid + 1;
    }
    return lo;
}
tcTU > T lstTrue(T lo, T hi, U f) {
    --lo, assert(lo <= hi);
    while (lo < hi) {
        T mid = lo + (hi - lo + 1) / 2;
        f(mid) ? lo = mid : hi = mid - 1;
    }
    return lo;
}

constexpr int pct(int x) { return __builtin_popcount(x); } // # of bits set
constexpr int p2(int x) { return 1 << x; }
constexpr int msk2(int x) { return p2(x) - 1; }
constexpr int log_2(int a) { return a ? (8 * sizeof(a)) - 1 - __builtin_clz(a) : -1; } // Floor of log_2(a); index of highest 1-bit
constexpr int next_pow_2(int a) { return a > 0 ? 1 << log_2(2 * a - 1) : 0; }          // 16->16, 13->16, (a<=0)->0

// INPUT
tcT > void re(complex<T> &c);
tcTU > void re(pair<T, U> &p);
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
tcTU > void re(pair<T, U> &p) { re(p.f, p.s); }
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
#ifdef asr
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
tcTU > str ts(pair<T, U> p);
tcT > str ts(T v) { // containers with begin(), end()
#ifdef asr
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
tcTU > str ts(pair<T, U> p) {
#ifdef asr
    return "(" + ts(p.f) + ", " + ts(p.s) + ")";
#else
    return ts(p.f) + " " + ts(p.s);
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

// DEBUG
void DBG() { cerr << "]" << endl; }
tcTUU > void DBG(const T &t, const U &...u) {
    cerr << ts(t);
    if (sizeof...(u)) cerr << ", ";
    DBG(u...);
}
#ifdef asr // chk -> fake assert
#define dbg(...) cerr << "Line(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#define chk(...) \
    if (!(__VA_ARGS__)) cerr << "Line(" << __LINE__ << ") -> function(" << __FUNCTION__ << ") -> CHK FAILED: (" << #__VA_ARGS__ << ")" << '\n', exit(0);
#else
#define dbg(...) 0
#define chk(...) 0
#endif

template <int MOD, int RT>
struct mint {
    static const int mod = MOD;
    static constexpr mint rt() { return RT; } // primitive root for FFT
    int v;
    explicit operator int() const { return v; } // explicit -> don't silently convert to int
    mint() { v = 0; }
    mint(ll _v) {
        v = int((-MOD < _v && _v < MOD) ? _v : _v % MOD);
        if (v < 0) v += MOD;
    }
    friend bool operator==(const mint &a, const mint &b) { return a.v == b.v; }
    friend bool operator!=(const mint &a, const mint &b) { return !(a == b); }
    friend bool operator<(const mint &a, const mint &b) { return a.v < b.v; }
    friend void re(mint &a) {
        ll x;
        re(x);
        a = mint(x);
    }
    friend str ts(mint a) { return ts(a.v); }

    mint &operator+=(const mint &m) {
        if ((v += m.v) >= MOD) v -= MOD;
        return *this;
    }
    mint &operator-=(const mint &m) {
        if ((v -= m.v) < 0) v += MOD;
        return *this;
    }
    mint &operator*=(const mint &m) {
        v = (ll)v * m.v % MOD;
        return *this;
    }
    mint &operator/=(const mint &m) { return (*this) *= inv(m); }
    friend mint pow(mint a, ll p) {
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
typedef mint<MOD, 5> mi; // 5 is primitive root for both common mods
typedef vector<mi> vmi;
typedef pair<mi, mi> pmi;
typedef vector<pmi> vpmi;

struct splitmix64_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

tcTU, typename Hash = splitmix64_hash > using hash_map = gp_hash_table<T, U, Hash>;
tcT, typename Hash = splitmix64_hash > using hash_set = hash_map<T, null_type, Hash>;
tcT > using ord_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
/*
Source : https://codeforces.com/blog/entry/11080
Note on using less_equal as comparison function to use it as a multiset:
    _GLIBCXX_DEBUG must not be defined, otherwise some internal check will fail.
    find will always return end.
    lower_bound works like upper_bound in normal set (to return the first element > it)
    upper_bound works like lower_bound in normal set (to return the first element >= it)
    find_by_order and order_of_key works properly (unlike the 2 functions above).
*/
tcT > using ord_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

mt19937 rng((unsigned int)std::chrono::steady_clock::now().time_since_epoch().count()); // mt19937 rng(61378913);
// shuffle(permutation.begin(), permutation.end(), rng);
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const long double eps = 1e-7;
const long double PI = 3.14159265358979323846L;
const long long lINF = 1e18L + 007;
const int iINF = 1e9 + 007;

const int tasz = 1e6 + 007;
ll a[tasz];
ll b[tasz];
ll c[tasz];




void solve() {
    ll n, k;
    re(n, k);
    pqg<ll> s;
    ll t = n;
    while(t){
        s.push(t % 10);
        t /= 10;
    }
    // dbg(s.top());
    while(k--){
        ll x = (s.top()) + 1;
        if (x >= 10) break;
        dbg(s.top());
        s.pop();
        s.push(x);
    }
    ll ans = 1;
    while(!s.empty()){
        ans *= s.top();
        s.pop();
    }
    ps(ans);
}

int main() {

#ifdef asr
    auto begin = chrono::high_resolution_clock::now();
#endif

    vamos;

    fix(15);

    int TT = 1;
    cin >> TT;
    f1r(TC, 1, TT)
        solve();

    #ifdef asr
    auto end = chrono::high_resolution_clock::now();
    cout << setprecision(2) << fixed;
    cout << "Execution time: " << chrono::duration_cast<chrono::duration<double>>(end - begin).count() * 1000 << " ms" << endl;
#endif

    return 0;
}