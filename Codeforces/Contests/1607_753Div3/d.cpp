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
// ll r[tasz];
// ll b[tasz];

// You are given an array of integers a of length n. The elements of the array can be either different or the same.

// Each element of the array is colored either blue or red. There are no unpainted elements in the array. One of the two operations described below can be applied to an array in a single step:

// either you can select any blue element and decrease its value by 1;
// or you can select any red element and increase its value by 1.
// Situations in which there are no elements of some color at all are also possible. For example, if the whole array is colored blue or red, one of the operations becomes unavailable.

// Determine whether it is possible to make 0 or more steps such that the resulting array is a permutation of numbers from 1 to n?

// In other words, check whether there exists a sequence of steps (possibly empty) such that after applying it, the array a contains in some order all numbers from 1 to n (inclusive), each exactly once.

// Input
// The first line contains an integer t (1≤t≤104) — the number of input data sets in the test.

// The description of each set of input data consists of three lines. The first line contains an integer n (1≤n≤2⋅105) — the length of the original array a. The second line contains n integers a1, a2, ..., an (−109≤ai≤109) — the array elements themselves.

// The third line has length n and consists exclusively of the letters 'B' and/or 'R': ith character is 'B' if ai is colored blue, and is 'R' if colored red.

// It is guaranteed that the sum of n over all input sets does not exceed 2⋅105.

// Output
// Print t lines, each of which contains the answer to the corresponding test case of the input. Print YES as an answer if the corresponding array can be transformed into a permutation, and NO otherwise.

// You can print the answer in any case (for example, the strings yEs, yes, Yes, and YES will be recognized as a positive answer).

// Example
// inputCopy
// 8
// 4
// 1 2 5 2
// BRBR
// 2
// 1 1
// BB
// 5
// 3 1 4 2 5
// RBRRB
// 5
// 3 1 3 1 3
// RBRRB
// 5
// 5 1 5 1 5
// RBRRB
// 4
// 2 2 2 2
// BRBR
// 2
// 1 -2
// BR
// 4
// -2 -1 4 0
// RRRR
// outputCopy
// YES
// NO
// YES
// YES
// NO
// YES
// YES
// YES

void solve() {
    ll n;
    cin >> n;
    f0r(i, n) cin >> a[i];
    string s;
    cin >> s;
    vl red, blue;
    f0r(i, n) {
        if (s[i] == 'R') red.pb(a[i]);
        else
            blue.pb(a[i]);
    }
    sort(all(red));
    sort(all(blue));
    ll j = 0, k = 0;
    f0r(i, n) {
        if (k <blue.size() && i + 1 <= blue[k]) k++;
        else if (j < red.size() && i + 1 >= red[j])
            j++;
        else {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES" << '\n';
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