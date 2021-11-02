#include <bits/stdc++.h>
using namespace std;

// #pragma GCC optimization ("O3")
// #pragma GCC optimization ("unroll-loops")
// #pragma optimization_level 3
// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define f0r(a, b) for (long long a = 0; a < (b); ++a)
#define f1r(a, b, c) for (long long a = (b); a < (c); ++a)
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

template <typename X, typename Y>
X &remin(X &x, const Y &y) { return x = (y < x) ? y : x; }
template <typename X, typename Y>
X &remax(X &x, const Y &y) { return x = (x < y) ? y : x; }
template <typename X, typename Y>
bool ckmin(X &x, const Y &y) { return (y < x) ? (x = y, 1) : 0; }
template <typename X, typename Y>
bool ckmax(X &x, const Y &y) { return (x < y) ? (x = y, 1) : 0; }

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

const long double eps = 1e-7;
const ld PI = 3.14159265358979323846;
const ll INF = 1e18 + 7;
const ll MOD = 1e9 + 7;
// const ll INF = 1e9 + 7;
// const ll MOD = 998244353;
// ll MOD;

// ll n, m, k, q, l, r, t, tmp, x, y, z, ans, res, cnt;
// string s, str;
const ll tasz = 1e6 + 7;
ll a[tasz];
ll l[tasz];
ll c[tasz];

void solve() {
    ll n;
    cin >> n;
    vpl end_beg(n);
    f0r(i, n) cin >> end_beg[i].ss >> end_beg[i].ff;
    sort(all(end_beg));

    ll cnt = 0, end = -1;
    for(auto i:end_beg){
        if (end <= i.ss) end = i.ff, cnt++;
    }
    cout << cnt << "\n";
}

int main() {

#ifdef asr
    auto begin = chrono::high_resolution_clock::now();
#endif

    vamos;

    fix(15);

    int T = 1;
    // cin >> T;
    while (T--)
        solve();

#ifdef asr
    auto end = chrono::high_resolution_clock::now();
    cout << setprecision(2) << fixed;
    cout << "Execution time: " << chrono::duration_cast<chrono::duration<double>>(end - begin).count() * 1000 << " ms" << endl;
#endif

    return 0;
}