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

// B. Diameter of Graph
// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output
// CQXYM wants to create a connected undirected graph with n nodes and m edges, and the diameter of the graph must be strictly less than k−1. Also, CQXYM doesn't want a graph that contains self-loops or multiple edges (i.e. each edge connects two different vertices and between each pair of vertices there is at most one edge).

// The diameter of a graph is the maximum distance between any two nodes.

// The distance between two nodes is the minimum number of the edges on the path which endpoints are the two nodes.

// CQXYM wonders whether it is possible to create such a graph.

// Input
// The input consists of multiple test cases.

// The first line contains an integer t(1≤t≤105) — the number of test cases. The description of the test cases follows.

// Only one line of each test case contains three integers n(1≤n≤109), m, k (0≤m,k≤109).

// Output
// For each test case, print YES if it is possible to create the graph, or print NO if it is impossible. You can print each letter in any case (upper or lower).

// Example
// inputCopy
// 5
// 1 0 3
// 4 5 3
// 4 6 3
// 5 4 1
// 2 1 1
// outputCopy
// YES
// NO
// YES
// NO
// NO



const ll tasz = 1e6 + 7;




void solve() {
    ll n, m, k;
    cin >> n >> m >> k;

    if(k<2||m>(n*(n-1)/2)||m<n-1){
        cout << "NO\n";
        return;
    }
    if(k==2){
        if(n==1&&m==0){
            cout << "YES\n";
            return;
        }else{
            cout << "NO\n";
            return;
        }
    }
    if(k==3){
        if(m==(n*(n-1)/2)){
            cout << "YES\n";
            return;
        }else {
            cout << "NO\n";
            return;
        }
    }if(k>3){
        if(m>=n-1){
            cout << "YES\n";
            return;
        }else {
            cout << "NO\n";
            return;
        }
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