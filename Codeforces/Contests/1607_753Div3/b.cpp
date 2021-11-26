#include <bits/stdc++.h>
using namespace std;

// #pragma GCC optimization ("O3")
// #pragma GCC optimization ("unroll-loops")
// #pragma optimization_level 3
// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define f0r(a, b) for (long long a = 0; a < (b); ++a)
#define f1r(a, b, c) for (long long a = (b); a < (c); ++a)
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


template<typename X, typename Y> X& remin(X& x, const Y& y) { return x = (y < x) ? y : x; }
template<typename X, typename Y> X& remax(X& x, const Y& y) { return x = (x < y) ? y : x; }
template<typename X, typename Y> bool ckmin(X& x, const Y& y) { return (y < x) ? (x=y,1):0; }
template<typename X, typename Y> bool ckmax(X& x, const Y& y) { return (x < y) ? (x=y,1):0; }


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

const long double eps = 1e-7;
const ld PI = 3.14159265358979323846;
const ll INF = 1e18 + 7;
const ll MOD = 1e9 + 7;
// const ll INF = 1e9 + 7;
// const ll MOD = 998244353;
// ll MOD;


// ll n, m, k, q, l, r, t, tmp, x, y, z, ans, res, cnt;
// string s, str;
const ll tasz = 1e6 + 7;
// ll a[tasz];
// ll b[tasz];
// ll c[tasz];

// The grasshopper is located on the numeric axis at the point with coordinate x0.

// Having nothing else to do he starts jumping between integer points on the axis. Making a jump from a point with coordinate x with a distance d to the left moves the grasshopper to a point with a coordinate x−d, while jumping to the right moves him to a point with a coordinate x+d.

// The grasshopper is very fond of positive integers, so for each integer i starting with 1 the following holds: exactly i minutes after the start he makes a jump with a distance of exactly i. So, in the first minutes he jumps by 1, then by 2, and so on.

// The direction of a jump is determined as follows: if the point where the grasshopper was before the jump has an even coordinate, the grasshopper jumps to the left, otherwise he jumps to the right.

// For example, if after 18 consecutive jumps he arrives at the point with a coordinate 7, he will jump by a distance of 19 to the right, since 7 is an odd number, and will end up at a point 7+19=26. Since 26 is an even number, the next jump the grasshopper will make to the left by a distance of 20, and it will move him to the point 26−20=6.

// Find exactly which point the grasshopper will be at after exactly n jumps.

// Input
// The first line of input contains an integer t (1≤t≤104) — the number of test cases.

// Each of the following t lines contains two integers x0 (−1014≤x0≤1014) and n (0≤n≤1014) — the coordinate of the grasshopper's initial position and the number of jumps.

// Example
// input
// 9
// 0 1
// 0 2
// 10 10
// 10 99
// 177 13
// 10000000000 987654321
// -433494437 87178291199
// 1 0
// -1 1
// output
// -1
// 1
// 11
// 110
// 190
// 9012345679
// -87611785637
// 1
// 0
void solve() {
    ll x, n;
    cin >> x >> n;
    if(n==0) {
        cout << x << '\n';
        return;
    }
    ll ans = 1;
    if(((n-1)/2)%2) {
        ans -=5;
        ans+=-4*(((n-1)/4));
        if((n-1)%2)ans += n;
    }else{
        ans+=4*(((n-1)/4));
        if((n-1)%2&&n!=1)ans-=n;
    }
    if(x%2) x+=ans;
    else x-=ans;
    cout << x << '\n';
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