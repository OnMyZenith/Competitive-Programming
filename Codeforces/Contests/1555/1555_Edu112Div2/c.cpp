#include <bits/stdc++.h>
using namespace std;

// #pragma GCC optimize("Ofast")
// #pragma GCC target("avx,avx2,fma")

// #pragma GCC optimize ("O3")
// #pragma GCC target ("sse4")

#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma,tune=native")

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
#define trav(a,x) for (auto& a : x)
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

// C. Coin Rows
// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output
// Alice and Bob are playing a game on a matrix, consisting of 2 rows and m columns. The cell in the i-th row in the j-th column contains ai,j coins in it.

// Initially, both Alice and Bob are standing in a cell (1,1). They are going to perform a sequence of moves to reach a cell (2,m).

// The possible moves are:

// Move right — from some cell (x,y) to (x,y+1);
// Move down — from some cell (x,y) to (x+1,y).
// First, Alice makes all her moves until she reaches (2,m). She collects the coins in all cells she visit (including the starting cell).

// When Alice finishes, Bob starts his journey. He also performs the moves to reach (2,m) and collects the coins in all cells that he visited, but Alice didn't.

// The score of the game is the total number of coins Bob collects.

// Alice wants to minimize the score. Bob wants to maximize the score. What will the score of the game be if both players play optimally?

// Input
// The first line contains a single integer t (1≤t≤104) — the number of testcases.

// Then the descriptions of t testcases follow.

// The first line of the testcase contains a single integer m (1≤m≤105) — the number of columns of the matrix.

// The i-th of the next 2 lines contain m integers ai,1,ai,2,…,ai,m (1≤ai,j≤104) — the number of coins in the cell in the i-th row in the j-th column of the matrix.

// The sum of m over all testcases doesn't exceed 105.

// Output
// For each testcase print a single integer — the score of the game if both players play optimally.

// Example
// inputCopy
// 3
// 3
// 1 3 7
// 3 5 1
// 3
// 1 3 9
// 3 5 1
// 1
// 4
// 7
// outputCopy
// 7
// 8
// 0



const ll tasz = 1e6 + 7;
ll a[2][tasz];
ll t[tasz];
ll b[tasz];




void solve() {
    // #warning: Switch to the Global larger array size after debugging
// ll a[2][4];
// ll t[4];
// ll b[4];
    ll m;
    cin >> m;
    f0r(i, 2) f0r(j, m) cin >> a[i][j];
    f0r(i, m+1) t[i] = 0;
    f0r(i, m+1) b[i] = 0;

    f1r(i,1, m-1) {
        b[i]=a[1][i-1];
        if(i>0)b[i]+=b[i-1];
    }
    f1rd(i,m-2,0){
        t[i]=a[0][i+1];
        if(i<m-1)t[i]+=t[i+1];
    }
    
    ll sum = INF;
    f0r(i, m) {
        ckmin(sum, max(t[i] , b[i]));
    }
    cout<<sum<<endl;

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