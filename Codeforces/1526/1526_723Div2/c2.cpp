#include <bits/stdc++.h>
using namespace std;

// #pragma GCC optimize("Ofast")
// #pragma GCC target("avx,avx2,fma")

// #pragma GCC optimize ("O3")
// #pragma GCC target ("sse4")

// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma,tune=native")

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

// C2. Potions (Hard Version)
// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output
// This is the hard version of the problem. The only difference is that in this version n≤200000. You can make hacks only if both versions of the problem are solved.

// There are n potions in a line, with potion 1 on the far left and potion n on the far right. Each potion will increase your health by ai when drunk. ai can be negative, meaning that potion will decrease will health.

// You start with 0 health and you will walk from left to right, from first potion to the last one. At each potion, you may choose to drink it or ignore it. You must ensure that your health is always non-negative.

// What is the largest number of potions you can drink?

// Input
// The first line contains a single integer n (1≤n≤200000) — the number of potions.

// The next line contains n integers a1, a2, ... ,an (−109≤ai≤109) which represent the change in health after drinking that potion.

// Output
// Output a single integer, the maximum number of potions you can drink without your health becoming negative.

// Example
// inputCopy
// 6
// 4 -4 1 -3 1 -3
// outputCopy
// 5
// Note
// For the sample, you can drink 5 potions by taking potions 1, 3, 4, 5 and 6. It is not possible to drink all 6 potions because your health will go negative at some point

const ll tasz = 1e6 + 7;
// ll a[tasz];
// ll cnt[tasz];
// ll posSUm[tasz];
// ll sum[tasz];

#include <bits/extc++.h>
using namespace __gnu_pbds;
struct custom_hash {
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

// unordered_map<ll, ll, custom_hash> safe_map;
gp_hash_table<pl, ll, custom_hash> ways_hlt_idx;

void solve() {
    ll n;
    cin >> n;
    vl a(n), cnt(n), posSUm(n), sum(n);
    f0r(i, n) cin >> a[i], posSUm[i] = (i ? posSUm[i - 1] : 0) + a[i] > 0 ? a[i] : 0;

    for (int k = 0; k < n; k++) {
        ways_hlt_idx[{((a[k]>=0)?a[k]:0),k}]=(a[k]>=0);
        // sum[k] = (a[k] < 0 ? 0 : a[k]);
        for (int i = 0; i < k; i++) {
            if (sum[i] + a[k] >= 0) {
                if(ckmax(cnt[k], cnt[i] + 1)) sum[k] = sum[i] + a[k];
            }
        }
    }
    ll ans = 0;
    f0r(i, n) ckmax(ans, cnt[i]);
    cout << ans << endl;
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