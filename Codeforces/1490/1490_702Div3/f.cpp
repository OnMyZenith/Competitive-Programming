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
#define vamos {ios_base::sync_with_stdio(false);cin.tie(nullptr);}
#define fix(prec) {cout << setprecision(prec) << fixed;}
#define mp make_pair
#define ff first
#define ss second
#define all(v) v.begin(), v.end()
#define ai(a, n) for (int ele = 0; ele < n; ele++) cin >> a[ele];
#define ain(a, lb, rb) for (int ele = lb; ele <= rb; ele++) cin >> a[ele];
#define ao(a, n) {for (int ele = 0; ele < (n); ele++) { if (ele) cout << " "; cout << a[ele]; } cout << '\n';}
#define aout(a, lb, rb) {for (int ele = (lb); ele <= (rb); ele++) { if (ele > (lb)) cout << " "; cout << a[ele]; } cout << '\n';}
#define sz(x) ((long long) x.size())
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

template<typename X, typename Y> X& remin(X& x, const Y& y) { return x = (y < x) ? y : x; }
template<typename X, typename Y> X& remax(X& x, const Y& y) { return x = (x < y) ? y : x; }
template<typename X, typename Y> bool ckmin(X& x, const Y& y) { return (y < x) ? (x=y,1):0; }
template<typename X, typename Y> bool ckmax(X& x, const Y& y) { return (x < y) ? (x=y,1):0; }


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

// F. Equalize the Array
// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output
// Polycarp was gifted an array a of length n. Polycarp considers an array beautiful if there exists a number C, such that each number in the array occurs either zero or C times. Polycarp wants to remove some elements from the array a to make it beautiful.

// For example, if n=6 and a=[1,3,2,1,4,2], then the following options are possible to make the array a array beautiful:

// Polycarp removes elements at positions 2 and 5, array a becomes equal to [1,2,1,2];
// Polycarp removes elements at positions 1 and 6, array a becomes equal to [3,2,1,4];
// Polycarp removes elements at positions 1,2 and 6, array a becomes equal to [2,1,4];
// Help Polycarp determine the minimum number of elements to remove from the array a to make it beautiful.

// Input
// The first line contains one integer t (1≤t≤104) — the number of test cases. Then t test cases follow.

// The first line of each test case consists of one integer n (1≤n≤2⋅105) — the length of the array a.

// The second line of each test case contains n integers a1,a2,…,an (1≤ai≤109) — array a.

// It is guaranteed that the sum of n over all test cases does not exceed 2⋅105.

// Output
// For each test case, output one integer — the minimum number of elements that Polycarp has to remove from the array a to make it beautiful.

// Example
// inputCopy
// 3
// 6
// 1 3 2 1 4 2
// 4
// 100 100 4 100
// 8
// 1 2 3 3 3 2 6 6
// outputCopy
// 2
// 1
// 2




const ll tasz = 1e6 + 7;
ll a[tasz];




void solve() {
    ll n;
    cin >> n;
    f0r(i, n) cin >> a[i];
    map<ll, ll> m;
    f0r(i, n) m[a[i]]++;
    vl f;
    for(auto i:m)
        f.pb(i.ss);
    sort(all(f));
    ll s = sz(f);
    ll area = 0, tot = 0;
    f0r(i, s) tot += f[i], ckmax(area, f[i] * (s - i));
    cout << tot - area << '\n';
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
    cout << "Execution time: " << chrono::duration_cast<chrono::duration<double>>(end - begin).count()*1000 << " ms" << endl;
#endif

    return 0;
}