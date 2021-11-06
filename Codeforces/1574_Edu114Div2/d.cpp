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

// D. The Strongest Build
// time limit per test3 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output
// Ivan is playing yet another roguelike computer game. He controls a single hero in the game. The hero has n equipment slots. There is a list of ci items for the i-th slot, the j-th of them increases the hero strength by ai,j. The items for each slot are pairwise distinct and are listed in the increasing order of their strength increase. So, ai,1<ai,2<⋯<ai,ci.

// For each slot Ivan chooses exactly one item. Let the chosen item for the i-th slot be the bi-th item in the corresponding list. The sequence of choices [b1,b2,…,bn] is called a build.

// The strength of a build is the sum of the strength increases of the items in it. Some builds are banned from the game. There is a list of m pairwise distinct banned builds. It's guaranteed that there's at least one build that's not banned.

// What is the build with the maximum strength that is not banned from the game? If there are multiple builds with maximum strength, print any of them.

// Input
// The first line contains a single integer n (1≤n≤10) — the number of equipment slots.

// The i-th of the next n lines contains the description of the items for the i-th slot. First, one integer ci (1≤ci≤2⋅105) — the number of items for the i-th slot. Then ci integers ai,1,ai,2,…,ai,ci (1≤ai,1<ai,2<⋯<ai,ci≤108).

// The sum of ci doesn't exceed 2⋅105.

// The next line contains a single integer m (0≤m≤105) — the number of banned builds.

// Each of the next m lines contains a description of a banned build — a sequence of n integers b1,b2,…,bn (1≤bi≤ci).

// The builds are pairwise distinct, and there's at least one build that's not banned.

// Output
// Print the build with the maximum strength that is not banned from the game. If there are multiple builds with maximum strength, print any of them.

// Examples
// inputCopy
// 3
// 3 1 2 3
// 2 1 5
// 3 2 4 6
// 2
// 3 2 3
// 3 2 2
// outputCopy
// 2 2 3 
// inputCopy
// 3
// 3 1 2 3
// 2 1 5
// 3 2 4 6
// 2
// 3 2 3
// 2 2 3
// outputCopy
// 1 2 3
// inputCopy
// 3
// 3 1 2 3
// 2 1 5
// 3 2 4 6
// 2
// 3 2 3
// 2 2 3
// outputCopy
// 3 2 2
// inputCopy
// 4
// 1 10
// 1 4
// 1 7
// 1 3
// 0
// outputCopy
// 1 1 1 1 



const ll tasz = 1e6 + 7;
// ll a[tasz];
ll b[tasz];
ll c[tasz];




void solve() {
    ll n;
    cin >> n;
    vvl a(n);
    f0r(i, n) {
        cin >> c[i];
        vl tmp(c[i]);
        f0r(j,c[i]) {
            cin >> tmp[j];
        }
        a[i] = tmp;
    }
    ll m;
    cin >> m;
    vvl b(m);
    f0r(i, m){
        vl tmp(n);
        f0r(j, n) cin>>tmp[j];
        b[i] = tmp;
    }
    
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