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

// You are given a number n (divisible by 3) and an array a[1…n]. In one move, you can increase any of the array elements by one. Formally, you choose the index i (1≤i≤n) and replace ai with ai+1. You can choose the same index i multiple times for different moves.

// Let's denote by c0, c1 and c2 the number of numbers from the array a that have remainders 0, 1 and 2 when divided by the number 3, respectively. Let's say that the array a has balanced remainders if c0, c1 and c2 are equal.

// For example, if n=6 and a=[0,2,5,5,4,8], then the following sequence of moves is possible:

// initially c0=1, c1=1 and c2=4, these values are not equal to each other. Let's increase a3, now the array a=[0,2,6,5,4,8];
// c0=2, c1=1 and c2=3, these values are not equal. Let's increase a6, now the array a=[0,2,6,5,4,9];
// c0=3, c1=1 and c2=2, these values are not equal. Let's increase a1, now the array a=[1,2,6,5,4,9];
// c0=2, c1=2 and c2=2, these values are equal to each other, which means that the array a has balanced remainders.
// Find the minimum number of moves needed to make the array a have balanced remainders.

// Input
// The first line contains one integer t (1≤t≤104). Then t test cases follow.

// The first line of each test case contains one integer n (3≤n≤3⋅104) — the length of the array a. It is guaranteed that the number n is divisible by 3.

// The next line contains n integers a1,a2,…,an (0≤ai≤100).

// It is guaranteed that the sum of n over all test cases does not exceed 150000.

// Output
// For each test case, output one integer — the minimum number of moves that must be made for the a array to make it have balanced remainders.

// Example
// inputCopy
// 4
// 6
// 0 2 5 5 4 8
// 6
// 2 0 2 1 0 0
// 9
// 7 1 3 4 2 10 3 9 6
// 6
// 0 1 2 3 4 5
// outputCopy
// 3
// 1
// 3
// 0
// Note
// The first test case is explained in the statements.

// In the second test case, you need to make one move for i=2.

// The third test case you need to make three moves:

// the first move: i=9;
// the second move: i=9;
// the third move: i=2.
// In the fourth test case, the values c0, c1 and c2 initially equal to each other, so the array a already has balanced remainders.



const ll tasz = 1e6 + 7;
ll a[tasz];



void solve() {
    ll n;
    cin >> n;
    f0r(i, n) cin >> a[i];
    ll c0 = 0, c1 = 0, c2 = 0;
    f0r(i, n) {
        if (a[i] % 3 == 0) c0++;
        else if (a[i] % 3 == 1) c1++;
        else c2++;
    }
    ll ans = 0;
    while(c0<n/3&&c2>n/3){
        c0++, c2--, ans++;
    }
    while(c1>n/3&&c2<n/3){
        c1--, c2++, ans++;
    }
    while(c0>n/3&&c1<n/3){
        c0--, c1++, ans++;
    }
    while(c0>n/3&&c2<n/3){
        c2++, c0--, ans+=2;
    }
    while(c0<n/3&&c1>n/3){
        c1--, c0++, ans+=2;
    }
    while(c2>n/3&&c1<n/3){
        c1++, c2--, ans+=2;
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