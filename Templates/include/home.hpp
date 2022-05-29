/* Author: OnMyZenith - https://github.com/OnMyZenith */
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;

#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
// #pragma GCC optimize("Ofast")
#pragma GCC target("avx2")
#pragma GCC target("popcnt,lzcnt,bmi,bmi2,tune=native")

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

template <typename T_vector> void ov(const T_vector &v, bool add_one = false, int start = -1, int end = -1) {
    if (start < 0) start = 0;
    if (end < 0) end = int(v.size());

    for (int i = start; i < end; i++)
        cout << v[i] + (add_one ? 1 : 0) << " \n"[i == end - 1];
}


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
const int MOD = 1e9 + 007; // 998244353;
mt19937 rng((unsigned int)std::chrono::steady_clock::now().time_since_epoch().count()); // mt19937 rng(61378913);
// e.g. shuffle(permutation.begin(), permutation.end(), rng);

const int __ = 1e6 + 007;  // 1e6 + 007 => int arr =   4 MB, ll arr =   8 MB
const int _ = 2e5 + 007;   // 2e5 + 007 => int arr = 0.8 MB, ll arr = 1.6 MB
const int dr[4] = {-1, 0, 1, 0}, dc[4] = {0, 1, 0, -1}; // URDL
const char dir[4] = {'U', 'R', 'D', 'L'};
