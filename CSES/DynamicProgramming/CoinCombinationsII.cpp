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

// Consider a money system consisting of n coins. Each coin has a positive integer value. Your task is to calculate the number of distinct ordered ways you can produce a money sum x using the available coins.

// For example, if the coins are {2,3,5} and the desired sum is 9, there are 3 ways:
// 2+2+5
// 3+3+3
// 2+2+2+3
// Input

// The first input line has two integers n and x: the number of coins and the desired sum of money.

// The second line has n distinct integers c1,c2,…,cn: the value of each coin.

// Output

// Print one integer: the number of ways modulo 109+7.

// Constraints
// 1≤n≤100
// 1≤x≤106
// 1≤ci≤106
// Example

// Input:
// 3 9
// 2 3 5

// Output:
// 3



// const int tasz = 2e6;
// int coins[101];
// int dp[tasz][101];

// void solve() {
//     int n, finalTarget;
//     cin >> n >> finalTarget;
//     f0r(i, n) cin >> coins[i];
    
//     dp[0][0] = 1;

//     // f1r(j, 1, n) {
//     //     f0r(i, finalTarget + 1){
//     //         dp[i][j] += dp[i][j - 1];

//     //         if (dp[i][j] >= MOD) 
//     //             dp[i][j] -= MOD;
            
//     //         if (i + coins[j - 1] <= finalTarget)
//     //             dp[i + coins[j - 1]][j] = dp[i][j];
//     //     }
//     // }
//     // cout << dp[finalTarget][n] << endl;

//     f1r(j, 1, n) {
//         f0r(i, finalTarget + 1){
//             dp[i][j] = dp[i][j - 1];
            
//             if(i - coins[j - 1]>=0)
//                 dp[i][j] += dp[i - coins[j - 1]][j];

//             if (dp[i][j] >= MOD) 
//                 dp[i][j] -= MOD;
//         }
//     }

//     cout << dp[finalTarget][n] << endl;
// }

// const int tasz = 1e6+007;
// int coins[101];
// int dp[101][tasz];
// void solve() {
//     int n, finalTarget;
//     cin >> n >> finalTarget;
//     for (int i = 0; i < n; i++) cin >> coins[i];
//     dp[0][0] = 1;
//     for (int c = 1; c <= n; c++) {
//         for (int t = 0; t <= finalTarget; t++){
//             dp[c][t] = dp[c - 1][t];
            
//             if(t - coins[c - 1]>=0)
//                 dp[c][t] += dp[c][t - coins[c - 1]];

//             if (dp[c][t] >= MOD) 
//                 dp[c][t] -= MOD;
//         }
//     }
//     cout << dp[n][finalTarget] << endl;

// }


const int tasz = 1e6+007;
int coins[101];
int dp[tasz];
void solve() {
    int n, finalTarget;
    cin >> n >> finalTarget;
    for (int i = 0; i < n; i++) cin >> coins[i];
    dp[0] = 1;
    for (int c = 1; c <= n; c++) {
        for (int t = 1; t <= finalTarget; t++){
            // dp[c][t] = dp[c - 1][t];
            
            if(t - coins[c - 1]>=0)
                dp[t] += dp[t - coins[c - 1]];

            if (dp[t] >= MOD) 
                dp[t] -= MOD;
        }
    }
    cout << dp[finalTarget] << endl;

}

int main() {

#ifdef asr
    auto begin = chrono::high_resolution_clock::now();
#endif

    vamos;

    fix(15);

    int T = 1;
    // cin >> T;
    while (T--)
        solve();

#ifdef asr
    auto end = chrono::high_resolution_clock::now();
    cout << setprecision(2) << fixed;
    cout << "Execution time: " << chrono::duration_cast<chrono::duration<double>>(end - begin).count()*1000 << " ms" << endl;
#endif

    return 0;
}