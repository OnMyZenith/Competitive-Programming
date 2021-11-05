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

// A permutation — is a sequence of length n integers from 1 to n, in which all the numbers occur exactly once. For example, [1], [3,5,2,1,4], [1,3,2] — permutations, and [2,3,2], [4,3,1], [0] — no.

// Polycarp was recently gifted a permutation a[1…n] of length n. Polycarp likes trees more than permutations, so he wants to transform permutation a into a rooted binary tree. He transforms an array of different integers into a tree as follows:

// the maximum element of the array becomes the root of the tree;
// all elements to the left of the maximum — form a left subtree (which is built according to the same rules but applied to the left part of the array), but if there are no elements to the left of the maximum, then the root has no left child;
// all elements to the right of the maximum — form a right subtree (which is built according to the same rules but applied to the right side of the array), but if there are no elements to the right of the maximum, then the root has no right child.
// For example, if he builds a tree by permutation a=[3,5,2,1,4], then the root will be the element a2=5, and the left subtree will be the tree that will be built for the subarray a[1…1]=[3], and the right one — for the subarray a[3…5]=[2,1,4]. As a result, the following tree will be built:

// The tree corresponding to the permutation a=[3,5,2,1,4].
// Another example: let the permutation be a=[1,3,2,7,5,6,4]. In this case, the tree looks like this:

// The tree corresponding to the permutation a=[1,3,2,7,5,6,4].
// Let us denote by dv the depth of the vertex av, that is, the number of edges on the path from the root to the vertex numbered av. Note that the root depth is zero. Given the permutation a, for each vertex, find the value of dv.

// Input
// The first line contains one integer t (1≤t≤100) — the number of test cases. Then t test cases follow.

// The first line of each test case contains an integer n (1≤n≤100) — the length of the permutation.

// This is followed by n numbers a1,a2,…,an — permutation a.

// Output
// For each test case, output n values — d1,d2,…,dn.

// Example
// inputCopy
// 3
// 5
// 3 5 2 1 4
// 1
// 1
// 4
// 4 3 1 2
// outputCopy
// 1 0 2 3 1 
// 0 
// 0 1 3 2 




const ll tasz = 1e6 + 7;
ll a[tasz];
ll res[tasz];
// // ll c[tasz];

void split(ll l , ll r, ll cnt=0){
    if (r < l) return;
    ll mx = -1, idx = -1;
    f1r(i, l, r) if (ckmax(mx, a[i])) idx = i;
    res[idx] = cnt;
    split(l, idx - 1,cnt+1);
    split(idx + 1, r,cnt+1);
}


void solve() {
    ll n;
    cin >> n;
    f0r(i, n) cin >> a[i];
    split(0, n - 1);
    aout(res, 0, n - 1);
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