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

// B. Combinatorics Homework
// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output
// You are given four integer values a, b, c and m.

// Check if there exists a string that contains:

// a letters 'A';
// b letters 'B';
// c letters 'C';
// no other letters;
// exactly m pairs of adjacent equal letters (exactly m such positions i that the i-th letter is equal to the (i+1)-th one).
// Input
// The first line contains a single integer t (1≤t≤104) — the number of testcases.

// Each of the next t lines contains the description of the testcase — four integers a, b, c and m (1≤a,b,c≤108; 0≤m≤108).

// Output
// For each testcase print "YES" if there exists a string that satisfies all the requirements. Print "NO" if there are no such strings.

// You may print every letter in any case you want (so, for example, the strings yEs, yes, Yes and YES will all be recognized as positive answer).

// Example
// inputCopy
// 3
// 2 2 1 0
// 1 1 1 1
// 1 2 3 2
// outputCopy
// YES
// NO
// YES
// Note
// In the first testcase strings "ABCAB" or "BCABA" satisfy the requirements. There exist other possible strings.

// In the second testcase there's no way to put adjacent equal letters if there's no letter that appears at least twice.

// In the third testcase string "CABBCC" satisfies the requirements. There exist other possible strings.





const ll tasz = 1e6 + 7;




void solve() {
    ll a[3], m;
    cin>>a[0]>>a[1]>>a[2]>>m;
    ll mx = a[0] + a[1] + a[2] -3;
    if (m > mx) {
        cout<<"NO"<<endl;
        return;
    }
    sort(a,a+3);
    ll mn;
    if(a[2] -1 >=a[0]+a[1]){
        mn = a[2] - a[1] - a[0] - 1;
    }else{
        ll x = a[1] + a[0] - a[2];
        mn =x/2 -a[0];
    }
    if (m < mn) {
        cout<<"NO"<<endl;
        return;
    }
    cout<<"YES"<<endl;
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