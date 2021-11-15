#include <bits/extc++.h>
#include <chrono>
// #include <bits/stdc++.h>
using namespace __gnu_pbds;
using namespace std;

// #pragma GCC optimize("Ofast")
// #pragma GCC target("avx,avx2,fma")

// #pragma GCC optimize ("O3")
// #pragma GCC target ("sse4")

#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma,tune=native")

#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define f0r(a, b) for (int a = 0; a < (b); ++a)
#define f1r(a, b, c) for (int a = (b); a <= (c); ++a)
#define f0rd(a, b) for (int a = (b); a >= 0; --a)
#define f1rd(a, b, c) for (int a = (b); a >= (c); --a)
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

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

typedef unordered_map<int, int, custom_hash> u_map;
typedef gp_hash_table<int, int, custom_hash> gp_h_table;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ord_set;

// because comp fns require strict ordering less_equal will FLIP upper_bound and lower_bound for ord_multiset
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ord_multiset;
// Also for some reason ord_multiset just gives an error on my compiler "msys64/mingw64/include/c++/10.3.0"
// Works on CF servers tho, (G++17 9.2.0)

const long double eps = 1e-7;
const ld PI = 3.14159265358979323846L;
const ll lINF = (ll)1e18L + 007;
const int MOD = 1e9 + 007;
const int iINF = 1e9 + 007;
// const int MOD = 998244353;
// ll MOD;

const int tasz = 1e6 + 007;
ll a[tasz];
// ll b[tasz];
// ll c[tasz];

void solve(int TC) {
    // #warning: Switch to the Global larger array size after debugging
    int n;
    cin >> n;
    string s;
    cin >> s;
    bool f = true;
    while (f) {
        f = false;
        f0r(k, 10) {
            bool f2 = true;
            while (f2) {
                f2 = false;
                f0r(i, sz(s) - 1) {
                    if (k==9&&s[i] =='9'&& s[i + 1]=='0') {
                        f2 = true;
                        f = true;
                        s = s.substr(0, i) + '1' + s.substr(i + 2);
                        break;
                    }
                    if (k<9&&s[i] == (char)('0' + k) && s[i + 1] == (char)('1' + k)) {
                        f2 = true;
                        f = true;
                        int r = k + 50;
                        if (r >= 58) r -= 10;
                        s = s.substr(0, i) + ((char)r) + s.substr(i + 2);
                        break;
                    }
                }
            }
        }
    }

    cout << "Case #" << TC << ": " << s << '\n';
}

int main() {

#ifdef asr
    auto begin = chrono::high_resolution_clock::now();
#endif

    vamos;

    fix(15);

    int TT = 1;
    cin >> TT;
    f1r(TC, 1, TT)
        solve(TC);

#ifdef asr
    auto end = chrono::high_resolution_clock::now();
    cout << setprecision(2) << fixed;
    cout << "Execution time: " << chrono::duration_cast<chrono::duration<double>>(end - begin).count() * 1000 << " ms" << endl;
#endif

    return 0;
}