#include <bits/stdc++.h>
using namespace std;

// #pragma GCC optimize("Ofast")
// #pragma GCC target("avx,avx2,fma")

// #pragma GCC optimize ("O3")
// #pragma GCC target ("sse4")

// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma,tune=native")

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

// B. Two Tables
// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output
// You have an axis-aligned rectangle room with width W and height H, so the lower left corner is in point (0,0) and the upper right corner is in (W,H).

// There is a rectangular table standing in this room. The sides of the table are parallel to the walls, the lower left corner is in (x1,y1), and the upper right corner in (x2,y2).

// You want to place another rectangular table in this room with width w and height h with the width of the table parallel to the width of the room.

// The problem is that sometimes there is not enough space to place the second table without intersecting with the first one (there are no problems with tables touching, though).

// You can't rotate any of the tables, but you can move the first table inside the room.

// Example of how you may move the first table.
// What is the minimum distance you should move the first table to free enough space for the second one?

// Input
// The first line contains the single integer t (1≤t≤5000) — the number of the test cases.

// The first line of each test case contains two integers W and H (1≤W,H≤108) — the width and the height of the room.

// The second line contains four integers x1, y1, x2 and y2 (0≤x1<x2≤W; 0≤y1<y2≤H) — the coordinates of the corners of the first table.

// The third line contains two integers w and h (1≤w≤W; 1≤h≤H) — the width and the height of the second table.

// Output
// For each test case, print the minimum distance you should move the first table, or −1 if there is no way to free enough space for the second table.

// Your answer will be considered correct if its absolute or relative error doesn't exceed 10−6.

// Example
// inputCopy
// 5
// 8 5
// 2 1 7 4
// 4 2
// 5 4
// 2 2 5 4
// 3 3
// 1 8
// 0 3 1 6
// 1 5
// 8 1
// 3 0 6 1
// 5 1
// 8 10
// 4 5 7 8
// 8 5
// outputCopy
// 1.000000000
// -1
// 2.000000000
// 2.000000000
// 0.000000000
// Note
// The configuration of the first test case is shown in the picture. But the movement of the first table is not optimal. One of the optimal movement, for example, is to move the table by (0,−1), so the lower left corner will move from (2,1) to (2,0). Then you can place the second table at (0,3)−(4,5).

// In the second test case, there is no way to fit both tables in the room without intersecting.

// In the third test case, you can move the first table by (0,2), so the lower left corner will move from (0,3) to (0,5).



const ll tasz = 1e6 + 7;
// ll a[tasz];
// // ll b[tasz];
// // ll c[tasz];




void solve() {
    // #warning: Switch to the Global larger array size after debugging
    ll W,H,x1,y1,x2,y2,w,h;
    cin>>W>>H>>x1>>y1>>x2>>y2>>w>>h;
    bool vPoss=false,hPoss=false;
    if(h<=H-(y2-y1))vPoss=true;
    if(w<=W-(x2-x1))hPoss=true;
    if(!vPoss&&!hPoss) {
        cout<<-1<<endl;
        return;
    }
    ll m = -INF, n = -INF;
    if(vPoss)m = max(H-y2,y1);
    if(hPoss)n = max(W-x2,x1);
    cout<<min(max(h-m,0LL),max(w-n,0LL))<<endl;



}


int main() {

#ifdef asr
    auto begin = chrono::high_resolution_clock::now();
#endif

    vamos;

    fix(9);

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