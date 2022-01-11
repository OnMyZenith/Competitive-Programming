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

// D. Xor of 3
// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output
// You are given a sequence a of length n consisting of 0s and 1s.

// You can perform the following operation on this sequence:

// Pick an index i from 1 to n−2 (inclusive).
// Change all of ai, ai+1, ai+2 to ai⊕ai+1⊕ai+2 simultaneously, where ⊕ denotes the bitwise XOR operation
// Find a sequence of at most n operations that changes all elements of a to 0s or report that it's impossible.
// We can prove that if there exists a sequence of operations of any length that changes all elements of a to 0s, then there is also such a sequence of length not greater than n.

// Input
// Each test contains multiple test cases. The first line contains the number of test cases t (1≤t≤104).

// The first line of each test case contains a single integer n (3≤n≤2⋅105) — the length of a.

// The second line of each test case contains n integers a1,a2,…,an (ai=0 or ai=1) — elements of a.

// It is guaranteed that the sum of n over all test cases does not exceed 2⋅105.

// Output
// For each test case, do the following:

// if there is no way of making all the elements of a equal to 0 after performing the above operation some number of times, print "NO".
// otherwise, in the first line print "YES", in the second line print k (0≤k≤n) — the number of operations that you want to perform on a, and in the third line print a sequence b1,b2,…,bk (1≤bi≤n−2) — the indices on which the operation should be applied.
// If there are multiple solutions, you may print any.

// Example
// inputCopy
// 3
// 3
// 0 0 0
// 5
// 1 1 1 1 0
// 4
// 1 0 0 1
// outputCopy
// YES
// 0
// YES
// 2
// 3 1
// NO
// Note
// In the first example, the sequence contains only 0s so we don't need to change anything.

// In the second example, we can transform [1,1,1,1,0] to [1,1,0,0,0] and then to [0,0,0,0,0] by performing the operation on the third element of a and then on the first element of a.

// In the third example, no matter whether we first perform the operation on the first or on the second element of a we will get [1,1,1,1], which cannot be transformed to [0,0,0,0].





const ll tasz = 1e6 + 7;
bool a[tasz];
// ll b[tasz];
// ll c[tasz];




void solve() {
    // bool a[10];
    ll n;
    cin >> n;
    f0r(i, n) {
        cin >> a[i];
    }
    ll ans = 0;
    vl res;
    f0rd(i, n-3){
        if (a[i] == 0 && a[i + 1] == 0 && a[i + 2] == 0) continue;
        ll x = a[i] ^ a[i+1] ^ a[i+2];
        if(x == 0) {
            ans++;
            res.pb(i+1);
            a[i] = a[i+1] = a[i+2] = 0;
        }
    }
    f0r(i, n) {
        if(a[i] == 1) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n" << ans << endl;
    f0r(i,sz(res)) {
        cout << res[i] << " ";
    }
    cout << endl;
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