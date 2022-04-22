/* Author: OnMyZenith - https://github.com/OnMyZenith */
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;

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

#ifndef ONLINE_JUDGE
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

#ifndef ONLINE_JUDGE
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

#ifndef ONLINE_JUDGE
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


#ifndef ONLINE_JUDGE
void DBG() { cerr << "]" << endl; }
template <class T, class... U > void DBG(const T &t, const U &...u) {
    cerr << to_string(t);
    if (sizeof...(u)) cerr << ", ";
    DBG(u...);
}
// chk -> fake assert
#define dbg(...) cerr << "Line(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
// #define chk(...) \
//     if (!(__VA_ARGS__)) cerr << "Line(" << __LINE__ << ") -> function(" << __FUNCTION__ << ") -> CHK FAILED: (" << #__VA_ARGS__ << ")" << '\n', exit(0);

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
template <class T> T powf(T a, long long b) { T r = 1; while (b) { if (b & 1) r *= a; b >>= 1; a *= a; } return r; }

template <typename T_vector> void ov(const T_vector &v, bool add_one = false, int start = -1, int end = -1) {
    if (start < 0) start = 0;
    if (end < 0) end = int(v.size());

    for (int i = start; i < end; i++)
        cout << v[i] + (add_one ? 1 : 0) << " \n"[i == end - 1];
}

// Check result <= hi
template <class T, class U> T ft(T lo, T hi, U f) {
    ++hi, assert(lo <= hi);
    while (lo < hi) {
        T mid = lo + (hi - lo) / 2;
        f(mid) ? hi = mid : lo = mid + 1;
    }
    return lo;
}
// Check result >= lo
template <class T, class U> T lt(T lo, T hi, U f) {
    --lo, assert(lo <= hi);
    while (lo < hi) {
        T mid = lo + (hi - lo + 1) / 2;
        f(mid) ? lo = mid : hi = mid - 1;
    }
    return lo;
}

template <class Fun>
class y_combinator_result {
    Fun fun_;
public:
    template <class T> explicit y_combinator_result(T &&fun) : fun_(std::forward<T>(fun)) {}
    template <class... Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};
template <class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }

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

// // 0.6s for 1e8 (GNU G++17 (64 bit 9.2.0, mysys 2))
// const int MAX_PR = 100'000'000;
// bitset<MAX_PR> isprime;
// vector<int> eratosthenesSieve(int lim) {

//     isprime.set();
//     isprime[0] = isprime[1] = 0;

//     for (int i = 4; i < lim; i += 2)
//         isprime[i] = 0;

//     for (int i = 3; i * i < lim; i += 2)
//         if (isprime[i])
//             for (int j = i * i; j < lim; j += i * 2)
//                 isprime[j] = 0;

//     vector<int> pr;
//     for (int i = 2; i < lim; i++)
//         if (isprime[i]) pr.push_back(i);

//     return pr;
// }

template <class T> struct segtree {
    // ALL INPUT FROM THE USER IS 0 BASED.
    int SZ; vector<T> v;

    constexpr int pct(int x) { return __builtin_popcount(x); }                                  // # of bits set
    constexpr int log_2(int x) { return x ? (8 * (int)sizeof(x)) - 1 - __builtin_clz(x) : -1; } // Floor of log_2(x); index of highest 1-bit
    constexpr int next_pow_2(int x) { return x > 0 ? 1 << log_2(2 * x - 1) : 0; }               // 16->16, 13->16, (x<=0)->0
    constexpr int log_2_ceil(int x) { return log_2(x) + int(__builtin_popcount(x) != 1); }      // Ceil of log_2(x);

    static constexpr T NEUTRAL_VAL = 1e9;  // Change this
    T f(T a, T b) { return min(a, b); };   // Change this

    // v i.e. the tree is indexed 1 based & a i.e. input data is indexed 0 based.
    void build(vector<T> &a) {
        SZ = 2 * next_pow_2(((int)a.size())); v.assign(SZ, NEUTRAL_VAL);
        for (int i = 0; i < ((int)a.size()); i++) v[SZ / 2 + i] = a[i];
        for (int i = SZ / 2 - 1; i >= 1; i--) v[i] = f(v[2 * i], v[2 * i + 1]);
    }

    // idx is 0 based
    void update(int idx, T x) {
        int i = SZ / 2 + idx; v[i] = x;
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

    void print() {
#ifndef ONLINE_JUDGE
        int nodes = 1, spaces = SZ, idx = 1;
        while (idx < SZ) {
            for (int j = 0; j < nodes; j++) {
                cout << setw(j ? 2 * spaces : spaces);
                if (v[idx] != NEUTRAL_VAL) cout << (v[idx]); else cout << ('_');
                idx++;
            }
            cout << '\n'; nodes *= 2; spaces /= 2;
        }
        for (int k = 0; k < 2 * SZ; k++) cout << "-\n"[k == 2 * SZ - 1];
#endif
    }
};

vector<vector<int>> reG(int n, int m, bool bi = 1) {
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        if(bi) adj[v].push_back(u);
    }
    return adj;
}

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

template <class T, class U, typename Hash = splitmix64_hash> using hash_map = gp_hash_table<T, U, Hash>;
template <class T, typename Hash = splitmix64_hash> using hash_set = hash_map<T, null_type, Hash>;


// Because multiset.erase(t) will erase all occurances of t!!
template <class T, class U> bool erase(T &t, const U &u) {
    auto it = t.find(u);
    if (it == end(t)) return false;
    t.erase(it); return true;
}

template <class T> using ord_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
/*
Source : https://codeforces.com/blog/entry/11080
Note on using less_equal as comparison function to use it as a multiset:
    _GLIBCXX_DEBUG must not be defined, otherwise some internal check will fail.
    find will always return end.
    lower_bound works like upper_bound in normal set (to return the first element > it)
    upper_bound works like lower_bound in normal set (to return the first element >= it)
    find_by_order and order_of_key works properly (unlike the 2 functions above).

Some more observations:
    erase(ord_mul_set.find(ele)); <-- doesn't work
    use this instead:
    auto it = ord_mul_set.upper_bound(ele); <-- actually gives lower_bound
    if(*it == ele) ord_mul_set.erase(it);
*/
template <class T> using ord_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

//these are checked at (1 + eps == 1) on CF, accuracy gets better near zero
const float epsf = 1e-7F;
const long double epsld = 1e-19L;
const double epsd = 2e-16;

const long double PI = 3.14159265358979323846L;
const long long LINF = 2e18L + 007;
const int IINF = 2e9 + 007;
// const int MOD = 1e9 + 007; // 998244353;
mt19937 rng((unsigned int)std::chrono::steady_clock::now().time_since_epoch().count()); // mt19937 rng(61378913);
// e.g. shuffle(permutation.begin(), permutation.end(), rng);

constexpr int pct(int x) { return __builtin_popcount(x); }                                  // # of bits set
constexpr int log_2(int x) { return x ? (8 * (int)sizeof(x)) - 1 - __builtin_clz(x) : -1; } // Floor of log_2(x); index of highest 1-bit
constexpr int next_pow_2(int x) { return x > 0 ? 1 << log_2(2 * x - 1) : 0; }               // 16->16, 13->16, (x<=0)->0
constexpr int log_2_ceil(int x) { return log_2(x) + int(__builtin_popcount(x) != 1); }      // Ceil of log_2(x);

const int __ = 1e6 + 007;  // 1e6 + 007 => int arr =   4 MB, ll arr =   8 MB
const int _ = 2e5 + 007;   // 2e5 + 007 => int arr = 0.8 MB, ll arr = 1.6 MB
const int dr[4] = {-1, 0, 1, 0}, dc[4] = {0, 1, 0, -1}; // URDL
const char dir[4] = {'U', 'R', 'D', 'L'};


vl a;
vl b;
vl c;


void solve() {
    int n; cin >> n;
    str s; cin >> s;

    vector<bool> a(1 << n);
    for (int i = 1; i < (1 << n); i++) a[i] = s[i - 1] == 'A';

    V<vb> h(1 << n);
    mi ans = 1;
    for (int i = (1 << (n)) - 1; i >= 1; i--) {
        h[i] = {a[i]};
        if(i < (1 << (n - 1))) {
            if(h[i * 2] != h[i * 2 + 1]) ans *= 2;
            copy(all(h[i * 2]), back_inserter(h[i]));
            copy(all(h[i * 2 + 1]), back_inserter(h[i]));
        }
    }
    ps(ans);
}

int main() {

#ifndef ONLINE_JUDGE
    auto begin = chrono::high_resolution_clock::now();
#endif

    vamos;
    
    
    // prepareFact(_);
    int TT = 1;
    // cin >> TT;
    f1r(TC, 1, TT)
        solve();

#ifndef ONLINE_JUDGE
    auto end = chrono::high_resolution_clock::now();
    cerr << setprecision(2) << fixed;
    cerr << "Execution time: " << chrono::duration_cast<chrono::duration<double>>(end - begin).count() * 1000 << " ms" << endl;
#endif

    return 0;
}