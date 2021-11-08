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

// A. PizzaForces
// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output
// PizzaForces is Petya's favorite pizzeria. PizzaForces makes and sells pizzas of three sizes: small pizzas consist of 6 slices, medium ones consist of 8 slices, and large pizzas consist of 10 slices each. Baking them takes 15, 20 and 25 minutes, respectively.

// Petya's birthday is today, and n of his friends will come, so he decided to make an order from his favorite pizzeria. Petya wants to order so much pizza that each of his friends gets at least one slice of pizza. The cooking time of the order is the total baking time of all the pizzas in the order.

// Your task is to determine the minimum number of minutes that is needed to make pizzas containing at least n slices in total. For example:

// if 12 friends come to Petya's birthday, he has to order pizzas containing at least 12 slices in total. He can order two small pizzas, containing exactly 12 slices, and the time to bake them is 30 minutes;
// if 15 friends come to Petya's birthday, he has to order pizzas containing at least 15 slices in total. He can order a small pizza and a large pizza, containing 16 slices, and the time to bake them is 40 minutes;
// if 300 friends come to Petya's birthday, he has to order pizzas containing at least 300 slices in total. He can order 15 small pizzas, 10 medium pizzas and 13 large pizzas, in total they contain 15⋅6+10⋅8+13⋅10=300 slices, and the total time to bake them is 15⋅15+10⋅20+13⋅25=750 minutes;
// if only one friend comes to Petya's birthday, he can order a small pizza, and the time to bake it is 15 minutes.
// Input
// The first line contains a single integer t (1≤t≤104) — the number of testcases.

// Each testcase consists of a single line that contains a single integer n (1≤n≤1016) — the number of Petya's friends.

// Output
// For each testcase, print one integer — the minimum number of minutes that is needed to bake pizzas containing at least n slices in total.

// Example
// inputCopy
// 6
// 12
// 15
// 300
// 1
// 9999999999999999
// 3
// outputCopy
// 30
// 40
// 750
// 15
// 25000000000000000
// 15




ll dp[481];

void solve() {
    // #warning: Switch to the Global larger array size after debugging
    ll n;
    cin >> n;
    ll ans = (ld)(n+n%2)*2.5;
    // if (n % 2 == 1) n++;
    if (n < 6) ans = 15;
    cout<<(ll)ans<<endl;
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