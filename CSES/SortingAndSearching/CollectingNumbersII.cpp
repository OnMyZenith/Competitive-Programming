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
const ll MOD = 1e9 + 7;
// const ll INF = 1e9 + 7;
// const ll MOD = 998244353;
// ll MOD;

// Time limit: 1.00 s Memory limit: 512 MB
// You are given an array that contains each number between 1…n exactly once. Your task is to collect the numbers from 1 to n in increasing order.

// On each round, you go through the array from left to right and collect as many numbers as possible.

// Given m operations that swap two numbers in the array, your task is to report the number of rounds after each operation.

// Input

// The first line has two integers n and m: the array size and the number of operations.

// The next line has n integers x1,x2,…,xn: the numbers in the array.

// Finally, there are m lines that describe the operations. Each line has two integers a and b: the numbers at positions a and b are swapped.

// Output

// Print m integers: the number of rounds after each swap.

// Constraints
// 1≤n,m≤2⋅105
// 1≤a,b≤n
// Example

// Input:
// 5 3
// 4 2 1 5 3
// 2 3
// 1 5
// 2 3

// Output:
// 2
// 3
// 4

const ll tasz = 1e6 + 7;
ll a[tasz];
ll idx[tasz];
// ll c[tasz];
ll n;

ll f(ll i) {
    ll res = 0;
    if (i > 0 && idx[i] < idx[i - 1]) res++;
    if (i < n - 1 && idx[i] > idx[i + 1]) res++;
    return res;
}

void solve() {
    ll m, t, ans = 1, l, r;
    cin >> n >> m;
    f0r(i, n) cin >> t, t--, a[i] = t, idx[t] = i;
    f1r(j, 1, n - 1) if (idx[j - 1] > idx[j]) ans++;
    f0r(i, m) {
        cin >> l >> r;
        l--, r--;
        ll ini= f(a[l]) + f(a[r]);
        if(abs(a[l] - a[r]) == 1) ini-=idx[min(a[l], a[r])]>idx[max(a[l], a[r])]?1:0;
        swap(idx[a[l]], idx[a[r]]);
        swap(a[l], a[r]);
        ll fin= f(a[l]) + f(a[r]);
        if(abs(a[l] - a[r]) == 1) fin-=idx[min(a[l], a[r])]>idx[max(a[l], a[r])]?1:0;
        ans-=ini-fin;
        cout << ans << endl;
    }
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