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

// C. Make Them Equal
// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output
// Theofanis has a string s1s2…sn and a character c. He wants to make all characters of the string equal to c using the minimum number of operations.

// In one operation he can choose a number x (1≤x≤n) and for every position i, where i is not divisible by x, replace si with c.

// Find the minimum number of operations required to make all the characters equal to c and the x-s that he should use in his operations.

// Input
// The first line contains a single integer t (1≤t≤104) — the number of test cases.

// The first line of each test case contains the integer n (3≤n≤3⋅105) and a lowercase Latin letter c — the length of the string s and the character the resulting string should consist of.

// The second line of each test case contains a string s of lowercase Latin letters — the initial string.

// It is guaranteed that the sum of n over all test cases does not exceed 3⋅105.

// Output
// For each test case, firstly print one integer m — the minimum number of operations required to make all the characters equal to c.

// Next, print m integers x1,x2,…,xm (1≤xj≤n) — the x-s that should be used in the order they are given.

// It can be proved that under given constraints, an answer always exists. If there are multiple answers, print any.

// Example
// inputCopy
// 3
// 4 a
// aaaa
// 4 a
// baaa
// 4 b
// bzyx
// outputCopy
// 0
// 1
// 2
// 2 
// 2 3




const ll tasz = 1e6 + 7;



// void solve() {
//     int n;
//     char c;
//     string s;
//     cin >> n >> c >> s;
//     bool case1 = true, case2 = false;
//     for (auto i : s)
//         if (i != c) case1 = false;
//     if (!case1 && s[n - 1] == c) case2 = true;
//     if (case1) {
//         cout << 0 << '\n';
//         return;
//     } else if (case2) {
//         cout << 1 << '\n';
//         // cout << n << '\n';
//         return;
//     }
//     set<int> cPos, prim;
//     for (int i = 1; i < n; i++)
//         if (s[i] == c) cPos.insert(i + 1);

//     int tmp = n;
//     while (n % 2 == 0) {
//         prim.insert(2);
//         n = n / 2;
//     }
//     for (int i = 3; i <= sqrt(n); i = i + 2) {
//         while (n % i == 0) {
//             prim.insert(i);
//             n = n / i;
//         }
//     }
//     if (n > 2)
//         prim.insert(n);
//     n = tmp;

//     set<int> result;
//     set_difference(cPos.begin(), cPos.end(), prim.begin(), prim.end(), inserter(result, result.end()));

//     if (result.size() == 0) {
//         int d = 0;
//         for (int i = 1; i <= n; i++)
//             if (n % i != 0) {
//                 d = i;
//                 break;
//             }
//         cout << 2 << '\n';
//         // cout << d << " " << n << '\n';
//     } else {
//         bool poss = true, pp = false;
//         int r;
//         for (auto it = result.begin(); it != result.end(); it++) {
//             poss = true;
//             int temp = *it;
//             r = *it;
//             for (int i = 2; i * temp < n; i++) {
//                 temp *= i;
//                 if (result.find(temp) == result.end()) {
//                     poss = false;
//                     break;
//                 }
//             }
//             if (poss) {
//                 pp = true;
//                 break;
//             }
//         }
//         if (pp) {
//             cout << 1 << '\n';
//             // cout << r << '\n';
//         } else {
//             int d = 0;
//             for (int i = 1; i <= n; i++)
//                 if (n % i != 0) {
//                     d = i;
//                     break;
//                 }
//             cout << 2 << '\n';
//             // cout << d << " " << n << '\n';
//         }
//     }
// }

void solve() {
    ll n;
    char c;
    string s;
    cin >> n >> c >> s;
    bool ok = true;
    f0r(i, n) if (s[i] != c) ok = false;
    if(ok){
        cout << 0 << '\n';
        return;
    }
    ll v = 0;
    f1rd(i, n - 1, n / 2)if (s[i] == c){ v = i + 1;break;}
    if(v==0){
        cout << 2 << '\n'
             << n << " " << n - 1 << '\n';
        return;
    }
    cout << 1 << '\n'
            << v << '\n';
    
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