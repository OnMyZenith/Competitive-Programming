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


int rand(int a, int b) {
    return a + rand() % (b - a + 1);
}

// Print n random numbers between l and r inclusive
void prand(int n, int l = 0, int r = 10) {
    f0r(i, n) cout << rand(l, r) << " \n"[i == n - 1];
}

// Print n random UNIQUE numbers between l and r inclusive
void puni(int n, int l = 0, int r = 10) {
    assert(n <= r - l + 1);
    set<int> used;
    f0r(i, n) {
        int x;
        do {
            x = rand(l, r);
        } while (used.count(x));
        cout << x << " \n"[i == n - 1];
        used.insert(x);
    }
}

// Print a random binary string of length n
void pbin(int n) {
    f0r(i, n) { pr(rand(0, 1)); }
    ps();
}

// Print a random set of characters of length n
void pstr(int n, char c = 'a', char d = 'z') {
    if (d < c) swap(c, d);
    f0r(i, n) { pr(char(c + rand(0, int(d - c)))); }
    ps();
}

//NOT necessarily connected // TODO: print connected graphs
// Print a graph with n nodes and m edges
void graph(int n_max, int m_max = -1) {
    int n = rand(2, n_max);     // if theres only one node then edges = 0, will get a seg falut trying to find rand(1,0) for no. of edges
    if (m_max < 0) m_max = n * (n - 1) / 2;
    int m = rand(1, m_max);

    ps(n,m);
    set<pi> used;
    f0r(i, m) {
        int x, y;
        do {
            x = rand(1, n);
            y = rand(1, n);
            if (x > y) swap(x, y);
        } while (x == y || used.count({x, y}));
        used.ins({x, y});
        ps(x, y);
    }
}

// Print a tree with max n_max nodes //from Errichto gen_tree2
void ptree(int n_max){ // Max Nodes
    int n = rand(2, n_max);
    ps(n,n-1,rand(1,n),rand(1,n));  // N nodes and n-1 edges
    vpi edges;
    for (int i = 2; i <= n; ++i) {
        edges.eb(rand(1, i - 1), i);
    }

    vi perm(n + 1); // re-naming vertices
    for (int i = 1; i <= n; ++i) {
        perm[i] = i;
    }
    random_shuffle(1+all(perm));

    random_shuffle(all(edges)); // random order of edges

    for (pi edge : edges) {
        int a = edge.ff, b = edge.ss;
        if (rand() % 2) {
            swap(a, b); // random order of two vertices
        }
        ps(perm[a], perm[b]);
    }
}

int main(int argc, char *argv[]) {
    // prepareFact(_);
    (void)argc;
    srand(atoi(argv[1]));
    vamos; fix(15);
    ps(1);      // One Test Case

    int n = rand(1, 10);
    ps(n);
    
    






    // pstr(10, 'l', 'k');
    // pstr(10);
    // prand(5);
    // pbin(20);
    // prand(10, 45, 55);
    // puni(12, 1, 12);
    // puni(12, 1, 10); // will fail the assertion

    return 0;
}