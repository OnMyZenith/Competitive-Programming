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
#define vamos                             \
    {                                     \
        ios_base::sync_with_stdio(false); \
        cin.tie(nullptr);                 \
    }
#define fix(prec) \
    { cout << setprecision(prec) << fixed; }
#define mp make_pair
#define ff first
#define ss second
#define all(v) v.begin(), v.end()
#define ai(a, n)                      \
    for (int ele = 0; ele < n; ele++) \
        cin >> a[ele];
#define ain(a, lb, rb)                   \
    for (int ele = lb; ele <= rb; ele++) \
        cin >> a[ele];
#define ao(a, n)                              \
    {                                         \
        for (int ele = 0; ele < (n); ele++) { \
            if (ele) cout << " ";             \
            cout << a[ele];                   \
        }                                     \
        cout << '\n';                         \
    }
#define aout(a, lb, rb)                            \
    {                                              \
        for (int ele = (lb); ele <= (rb); ele++) { \
            if (ele > (lb)) cout << " ";           \
            cout << a[ele];                        \
        }                                          \
        cout << '\n';                              \
    }
#define sz(x) ((long long)x.size())
#define trav(a, x) for (auto &a : x)
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

template <typename X, typename Y>
X &remin(X &x, const Y &y) { return x = (y < x) ? y : x; }
template <typename X, typename Y>
X &remax(X &x, const Y &y) { return x = (x < y) ? y : x; }
template <typename X, typename Y>
bool ckmin(X &x, const Y &y) { return (y < x) ? (x = y, 1) : 0; }
template <typename X, typename Y>
bool ckmax(X &x, const Y &y) { return (x < y) ? (x = y, 1) : 0; }

mt19937 rng((unsigned int)std::chrono::steady_clock::now().time_since_epoch().count());
// mt19937 rng(61378913);
/* usage - just do rng() */
/* shuffle(permutation.begin(), permutation.end(), rng); */

const long double eps = 1e-7;
const ld PI = 3.14159265358979323846;
const ll lINF = 1e18 + 007;
const int MOD = 1e9 + 007;
const int iINF = 1e9 + 007;
// const int MOD = 998244353;
// ll MOD;

const int tasz = 1e6 + 007;

int mx(int n){
    int ans = n%10;
    while(n/=10)
        remax(ans, n % 10);
    return ans;
}

//-----------------------------------------------------
// It was in DP section
// All DP sols give TLE -_-
//-----------------------------------------------------
//
// Recursive DP
//
// int F[tasz];
// bool ok[tasz];
// int f(int n){
//     F[n] = iINF;
//     f0r(i,(int)to_string(n).length()){
//         int x = n - (to_string(n)[i] - '0');
//         if(x>=0&&x<n){
//             if (ok[x]) F[n] = min(F[x] + 1, F[n]);
//             else
//                 F[n] = min(f(x) + 1, F[n]);
//         }
//     }
//     ok[n] = true;
//     return F[n];
// }

// void solve() {
    // #warning: Switch to the Global larger array size after debugging
    // int n;
    // cin >> n;
    // vi F(n + 1, iINF);
    // F[0] = 0;
    // ok[0] = true;
    // cout << f(n) << endl;

    // Push DP
    //
    // f0r(i, n) {
    //     for (int j = 1; j <= 9 && i + j <= n; j++) {
    //         if (to_string(i + j).find((char)j + '0') != string::npos)
    //             F[i + j] = min(F[i + j], F[i] + 1);
    //     }
    // }

    // Pull DP
    //
    // f1r(i, 1, n + 1) {
    //     for (int j = 1; j <= 9 && i - j >= 0; j++) {
    //         if (to_string(i).find((char)j + '0') != string::npos)
    //             F[i] = min(F[i], F[i - j] + 1);
    //     }
    // }

    // cout << F[n] << endl;
// }


int fin(int n){
    if (n == 0) return 0;
    return fin(n - mx(n)) + 1;
}

void solve() {
    // #warning: Switch to the Global larger array size after debugging
    int n;
    cin >> n;
    cout << fin(n) << endl;
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
    cout << "Execution time: " << chrono::duration_cast<chrono::duration<double>>(end - begin).count() * 1000 << " ms" << endl;
#endif

    return 0;
}