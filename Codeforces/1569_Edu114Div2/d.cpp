#include <bits/stdc++.h>
using namespace std;

// #pragma GCC optimize("Ofast")
// #pragma GCC target("avx,avx2,fma")

// #pragma GCC optimize ("O3")
// #pragma GCC target ("sse4")

#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma,tune=native")

#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define f0r(a, b) for (long long a = 0; a < (b); ++a)
#define f1r(a, b, c) for (long long a = (b); a <= (c); ++a)
#define f0rd(a, b) for (long long a = (b); a >= 0; --a)
#define f1rd(a, b, c) for (long long a = (b); a >= (c); --a)
#define pb push_back
#define vamos                             \
    {                                     \
        ios_base::sync_with_stdio(false); \
        cin.tie(nullptr);                 \
    }
#define fix(prec) \
    { cout << setprecision(prec) << fixed; }
#define mp make_pair
#define ff first
#define ss second
#define all(v) v.begin(), v.end()
#define ai(a, n)                      \
    for (int ele = 0; ele < n; ele++) \
        cin >> a[ele];
#define ain(a, lb, rb)                   \
    for (int ele = lb; ele <= rb; ele++) \
        cin >> a[ele];
#define ao(a, n)                              \
    {                                         \
        for (int ele = 0; ele < (n); ele++) { \
            if (ele) cout << " ";             \
            cout << a[ele];                   \
        }                                     \
        cout << '\n';                         \
    }
#define aout(a, lb, rb)                            \
    {                                              \
        for (int ele = (lb); ele <= (rb); ele++) { \
            if (ele > (lb)) cout << " ";           \
            cout << a[ele];                        \
        }                                          \
        cout << '\n';                              \
    }
#define sz(x) ((long long)x.size())
#define trav(a, x) for (auto &a : x)
#define lb lower_bound
#define ub upper_bound
#define eq equal_range
#define endl '\n'

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

typedef queue<int> qi;
typedef queue<ll> ql;
typedef queue<ld> qd;

typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<ld> vd;

typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<vd> vvd;

typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<ld, ld> pd;

typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<pd> vpd;

template <typename X, typename Y>
X &remin(X &x, const Y &y) { return x = (y < x) ? y : x; }
template <typename X, typename Y>
X &remax(X &x, const Y &y) { return x = (x < y) ? y : x; }
template <typename X, typename Y>
bool ckmin(X &x, const Y &y) { return (y < x) ? (x = y, 1) : 0; }
template <typename X, typename Y>
bool ckmax(X &x, const Y &y) { return (x < y) ? (x = y, 1) : 0; }

mt19937 rng((unsigned int)std::chrono::steady_clock::now().time_since_epoch().count());
// mt19937 rng(61378913);
/* usage - just do rng() */
/* shuffle(permutation.begin(), permutation.end(), rng); */

const long double eps = 1e-7;
const ld PI = 3.14159265358979323846;
const ll INF = 1e18 + 7;
const ll MOD = 1e9 + 7;
// const ll INF = 1e9 + 7;
// const ll MOD = 998244353;
// ll MOD;

// D. Inconvenient Pairs
// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output
// There is a city that can be represented as a square grid with corner points in (0,0) and (106,106).

// The city has n vertical and m horizontal streets that goes across the whole city, i. e. the i-th vertical streets goes from (xi,0) to (xi,106) and the j-th horizontal street goes from (0,yj) to (106,yj).

// All streets are bidirectional. Borders of the city are streets as well.

// There are k persons staying on the streets: the p-th person at point (xp,yp) (so either xp equal to some xi or yp equal to some yj, or both).

// Let's say that a pair of persons form an inconvenient pair if the shortest path from one person to another going only by streets is strictly greater than the Manhattan distance between them.

// Calculate the number of inconvenient pairs of persons (pairs (x,y) and (y,x) are the same pair).

// Let's recall that Manhattan distance between points (x1,y1) and (x2,y2) is |x1−x2|+|y1−y2|.

// Input
// The first line contains a single integer t (1≤t≤1000) — the number of test cases.

// The first line of each test case contains three integers n, m and k (2≤n,m≤2⋅105; 2≤k≤3⋅105) — the number of vertical and horizontal streets and the number of persons.

// The second line of each test case contains n integers x1,x2,…,xn (0=x1<x2<⋯<xn−1<xn=106) — the x-coordinates of vertical streets.

// The third line contains m integers y1,y2,…,ym (0=y1<y2<⋯<ym−1<ym=106) — the y-coordinates of horizontal streets.

// Next k lines contains description of people. The p-th line contains two integers xp and yp (0≤xp,yp≤106; xp∈{x1,…,xn} or yp∈{y1,…,ym}) — the coordinates of the p-th person. All points are distinct.

// It guaranteed that sum of n doesn't exceed 2⋅105, sum of m doesn't exceed 2⋅105 and sum of k doesn't exceed 3⋅105.

// Output
// For each test case, print the number of inconvenient pairs.

// Example
// inputCopy
// 2
// 2 2 4
// 0 1000000
// 0 1000000
// 1 0
// 1000000 1
// 999999 1000000
// 0 999999
// 5 4 9
// 0 1 2 6 1000000
// 0 4 8 1000000
// 4 4
// 2 5
// 2 2
// 6 3
// 1000000 1
// 3 8
// 5 8
// 8 8
// 6 8
// outputCopy
// 2
// 5

const ll tasz = 1e6 + 7;
// ll a[tasz];
ll x[tasz];
ll y[tasz];

void solve() {
    ll n, m, k;
    cin >> n >> m >> k;
    f0r(i, n) cin >> x[i];
    f0r(i, m) cin >> y[i];
    vl ver(m+1), hor(n+1);
    map<pair<pl,pl>,ll> exclude;
    f0r(i, k) {
        ll a, b;
        cin >> a >> b;
        ll x_hi = ub(x, x + n, a) - x, x_lo = lb(x, x + n, a) - x, y_hi = ub(y, y + m, b) - y, y_lo = lb(y, y + m, b) - y;
        bool on_x = x_hi - x_lo, on_y = y_hi - y_lo;

        if (on_x && on_y) continue;
        if (on_x) ver[y_lo]++, exclude[{{x_lo, x_lo}, {y_lo - 1, y_hi}}]++;
        else
            hor[x_lo]++, exclude[{{x_lo - 1, x_hi}, {y_lo, y_lo}}]++;
    }
    ll ans = 0;
    f0r(i, m + 1) ans += ver[i] * (ver[i] - 1) / 2;
    f0r(i, n + 1) ans += hor[i] * (hor[i] - 1) / 2;

    trav(i, exclude){
        // cout << "("<<i.ff.ff.ff << ", " << i.ff.ff.ss <<"), ("<<i.ff.ss.ff << ", " << i.ff.ss.ss << "):  " << i.ss << '\n';
        ans -= i.ss * (i.ss - 1) / 2;
    }

    cout << ans << endl;
}

int main() {

#ifdef asr
    auto begin = chrono::high_resolution_clock::now();
#endif

    vamos;

    fix(15);

    int T = 1;
    cin >> T;
    while (T--)
        solve();

#ifdef asr
    auto end = chrono::high_resolution_clock::now();
    cout << setprecision(2) << fixed;
    cout << "Execution time: " << chrono::duration_cast<chrono::duration<double>>(end - begin).count() * 1000 << " ms" << endl;
#endif

    return 0;
}