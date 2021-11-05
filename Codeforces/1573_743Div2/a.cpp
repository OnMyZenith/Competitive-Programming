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

// A. Countdown
// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output
// You are given a digital clock with n digits. Each digit shows an integer from 0 to 9, so the whole clock shows an integer from 0 to 10n−1. The clock will show leading zeroes if the number is smaller than 10n−1.

// You want the clock to show 0 with as few operations as possible. In an operation, you can do one of the following:

// decrease the number on the clock by 1, or
// swap two digits (you can choose which digits to swap, and they don't have to be adjacent).
// Your task is to determine the minimum number of operations needed to make the clock show 0.

// Input
// Each test contains multiple test cases. The first line contains the number of test cases t (1≤t≤103).

// The first line of each test case contains a single integer n (1≤n≤100) — number of digits on the clock.

// The second line of each test case contains a string of n digits s1,s2,…,sn (0≤s1,s2,…,sn≤9) — the number on the clock.

// Note: If the number is smaller than 10n−1 the clock will show leading zeroes.

// Output
// For each test case, print one integer: the minimum number of operations needed to make the clock show 0.

// Example
// inputCopy
// 7
// 3
// 007
// 4
// 1000
// 5
// 00000
// 3
// 103
// 4
// 2020
// 9
// 123456789
// 30
// 001678294039710047203946100020
// outputCopy
// 7
// 2
// 0
// 5
// 6
// 53
// 115
// Note
// In the first example, it's optimal to just decrease the number 7 times.

// In the second example, we can first swap the first and last position and then decrease the number by 1.

// In the third example, the clock already shows 0, so we don't have to perform any operations.



const ll tasz = 1e6 + 7;
ll a[tasz];
// ll b[tasz];
// ll c[tasz];




void solve() {
    ll n;
    cin >> n;
    string s;
    cin >> s;
    ll ans = s[n-1]-'0';
    for (int i = n-2; i >= 0; i--) {
        if (s[i]-'0') ans++;
        ans += s[i]-'0';
    }
    cout<<ans<<endl;
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