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
const ll INF = 1e18 + 7;
const ll MOD = 1e9 + 7;
// const ll INF = 1e9 + 7;
// const ll MOD = 998244353;
// ll MOD;

// C. Book
// time limit per test1.5 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output
// You are given a book with n chapters.

// Each chapter has a specified list of other chapters that need to be understood in order to understand this chapter. To understand a chapter, you must read it after you understand every chapter on its required list.

// Currently you don't understand any of the chapters. You are going to read the book from the beginning till the end repeatedly until you understand the whole book. Note that if you read a chapter at a moment when you don't understand some of the required chapters, you don't understand this chapter.

// Determine how many times you will read the book to understand every chapter, or determine that you will never understand every chapter no matter how many times you read the book.

// Input
// Each test contains multiple test cases. The first line contains the number of test cases t (1≤t≤2⋅104).

// The first line of each test case contains a single integer n (1≤n≤2⋅105) — number of chapters.

// Then n lines follow. The i-th line begins with an integer ki (0≤ki≤n−1) — number of chapters required to understand the i-th chapter. Then ki integers ai,1,ai,2,…,ai,ki (1≤ai,j≤n,ai,j≠i,ai,j≠ai,l for j≠l) follow — the chapters required to understand the i-th chapter.

// It is guaranteed that the sum of n and sum of ki over all testcases do not exceed 2⋅105.

// Output
// For each test case, if the entire book can be understood, print how many times you will read it, otherwise print −1.

// Example
// inputCopy
// 5
// 4
// 1 2
// 0
// 2 1 4
// 1 2
// 5
// 1 5
// 1 1
// 1 2
// 1 3
// 1 4
// 5
// 0
// 0
// 2 1 2
// 1 2
// 2 2 1
// 4
// 2 2 3
// 0
// 0
// 2 3 2
// 5
// 1 2
// 1 3
// 1 4
// 1 5
// 0
// outputCopy
// 2
// -1
// 1
// 2
// 5
// Note
// In the first example, we will understand chapters {2,4} in the first reading and chapters {1,3} in the second reading of the book.

// In the second example, every chapter requires the understanding of some other chapter, so it is impossible to understand the book.

// In the third example, every chapter requires only chapters that appear earlier in the book, so we can understand everything in one go.

// In the fourth example, we will understand chapters {2,3,4} in the first reading and chapter 1 in the second reading of the book.

// In the fifth example, we will understand one chapter in every reading from 5 to 1.

const ll tasz = 1e6 + 7;
ll a[tasz];
// ll b[tasz];
// ll c[tasz];

ll n;
// bool vis[tasz];
// vl adj[tasz];

void solve() {
    cin >> n;
    vvl req;
    string line;
    f0r(i, n +1) {
        getline(cin, line);
        istringstream buffer(line);
        req.emplace_back(istream_iterator<ll>{buffer}, istream_iterator<ll>{});
    }

    vector<bool> understood(n +1, false);
    understood[0] = true;
    ll ans = 0;

    while(true){
        ll understoodThisTime = 0;
        f0r(i, n +1){
            if(understood[i]) continue;
            bool ok = true;
            f0r(j, sz(req[i])){
                if(!understood[req[i][j]]&&i!=req[i][j]) ok = false;
            }
            if(ok){
                understoodThisTime++;
                understood[i] = true;
                f0r(j, sz(req[i])){
                    if(!understood[req[i][j]]&&i!=req[i][j]) ok = false;
                }
            }
        }
        if(understoodThisTime == 0) break;
        ans++;
    }
    f0r(i, n +1){
        if(!understood[i]){
            cout << -1 << endl;
            return;
        }
    }
    cout << ans << endl;
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
    cout << "Execution time: " << chrono::duration_cast<chrono::duration<double>>(end - begin).count() * 1000 << " ms" << endl;
#endif

    return 0;
}