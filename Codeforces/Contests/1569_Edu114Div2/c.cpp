#include <bits/stdc++.h>
using namespace std;

// #pragma GCC optimization ("O3")
// #pragma GCC optimization ("unroll-loops")
// #pragma optimization_level 3
// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

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
// const ll MOD = 1e9 + 7;
// const ll INF = 1e9 + 7;
const ll MOD = 998244353;
// ll MOD;

// C. Jury Meeting
// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output
// n people gathered to hold a jury meeting of the upcoming competition, the i-th member of the jury came up with ai tasks, which they want to share with each other.

// First, the jury decides on the order which they will follow while describing the tasks. Let that be a permutation p of numbers from 1 to n (an array of size n where each integer from 1 to n occurs exactly once).

// Then the discussion goes as follows:

// If a jury member p1 has some tasks left to tell, then they tell one task to others. Otherwise, they are skipped.
// If a jury member p2 has some tasks left to tell, then they tell one task to others. Otherwise, they are skipped.
// ...
// If a jury member pn has some tasks left to tell, then they tell one task to others. Otherwise, they are skipped.
// If there are still members with tasks left, then the process repeats from the start. Otherwise, the discussion ends.
// A permutation p is nice if none of the jury members tell two or more of their own tasks in a row.

// Count the number of nice permutations. The answer may be really large, so print it modulo 998244353.

// Input
// The first line contains a single integer t (1≤t≤104) — the number of test cases.

// The first line of the test case contains a single integer n (2≤n≤2⋅105) — number of jury members.

// The second line contains n integers a1,a2,…,an (1≤ai≤109) — the number of problems that the i-th member of the jury came up with.

// The sum of n over all test cases does not exceed 2⋅105.

// Output
// For each test case, print one integer — the number of nice permutations, taken modulo 998244353.

// Example
// inputCopy
// 4
// 2
// 1 2
// 3
// 5 5 5
// 4
// 1 3 3 7
// 6
// 3 4 2 1 3 3
// outputCopy
// 1
// 6
// 0
// 540

const ll tasz = 1e6 + 7;
ll a[tasz];

ll factorial(ll n) {
    if (n == 0)
        return 1;
    return (n * factorial(n - 1)) % MOD;
}

void solve() {
    ll n;
    cin >> n;
    ai(a, n);
    ll ans = 0;
    sort(a, a + n);
    if (a[n - 1] == a[n - 2]) {
        cout << factorial(n) << endl;
        return;
    }
    if (a[n - 1] > a[n - 2] + 1) {
        cout << 0 << endl;
        return;
    }
    ll cnt = equal_range(a, a + n, a[n - 2]).ss - equal_range(a, a + n, a[n - 2]).ff;
    ans = 1;
    ll tmp = n;
    while(tmp){
        if (tmp == cnt + 1) ans *= cnt;
        else
            ans *= tmp;
        tmp--;
        ans %= MOD;
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