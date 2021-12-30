/* Author: OnMyZenith - https://github.com/OnMyZenith */
#include <bits/extc++.h>
// #include <chrono>
// #include <bits/stdc++.h>
using namespace __gnu_pbds;
using namespace std;

// #pragma GCC optimize("Ofast")
// #pragma GCC target("avx,avx2,fma")

// #pragma GCC optimize ("O3")
// #pragma GCC target ("sse4")

// #pragma GCC optimize ("O3")
// #pragma GCC target ("avx2")

// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma,tune=native")

#define vamos ios_base::sync_with_stdio(false), cin.tie(nullptr);
#define fix(prec) cout << setprecision(prec) << fixed;

#define tcT template <class T
#define tcTU tcT, class U

#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define f0r(i, n) for (int i = 0; i < (n); ++i)
#define f1r(i, l, r) for (int i = (l); i <= (r); ++i)
#define f0rd(i, n) for (int i = (n); i >= 0; --i)
#define f1rd(i, l, r) for (int i = (l); i >= (r); --i)
#define each(i, a) for (auto &i : a)

#define ai(a, n) f0r(i, n) cin >> a[i];
#define ain(a, l, r) f1r(i, l, r) cin >> a[i];
#define ao(a, n) f0r(i, n) cout << a[i] << " ";
#define aout(a, l, r) f1r(i, l, r) cout << a[i] << " \n"[i == r];

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define ff first
#define ss second
#define lb lower_bound
#define ub upper_bound
#define ins insert
#define ft front()
#define bk back()
#define rsz resize
#define eq equal_range
#define nl '\n'

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define sor(v) sort(v.begin(), v.end())
#define soR(v) sort(v.rbegin(), v.rend())
#define sz(x) ((long long)x.size())
#define bg(x) x.begin()

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

typedef string str;
typedef vector<string> vs;
typedef vector<bool> vb;

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

tcT > using V = vector<T>;
tcT > using pqg = std::priority_queue<T, V<T>, greater<T>>;
tcT > using pq = std::priority_queue<T>;
tcT > using Q = queue<T>;

tcT > bool ckmin(T &x, const T &y) { return (y < x) ? (x = y, 1) : 0; }
tcT > bool ckmax(T &x, const T &y) { return (y > x) ? (x = y, 1) : 0; }
tcT > ll cdiv(T &a, T &b) { return (ll)(a / b + ((a ^ b) > 0 && a % b)); }
tcT > ll fdiv(T &a, T &b) { return (ll)(a / b - ((a ^ b) < 0 && a % b)); }
tcT > ll lwb(V<T> &a, const T &b) { return (ll)(lb(all(a), b) - bg(a)); }
tcT > ll upb(V<T> &a, const T &b) { return (ll)(ub(all(a), b) - bg(a)); }
tcT > void remDup(V<T> &v) { sort(all(v)), v.erase(unique(all(v)), end(v)); }

tcTU > T fstTrue(T lo, T hi, U f) {
    ++hi, assert(lo <= hi); // assuming f is increasing
    while (lo < hi) {       // find first index such that f is true
        T mid = lo + (hi - lo) / 2;
        f(mid) ? hi = mid : lo = mid + 1;
    }
    return lo;
}
tcTU > T lstTrue(T lo, T hi, U f) {
    --lo, assert(lo <= hi); // assuming f is decreasing
    while (lo < hi) {       // find last index such that f is true
        T mid = lo + (hi - lo + 1) / 2;
        f(mid) ? lo = mid : hi = mid - 1;
    }
    return lo;
}

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

typedef gp_hash_table<int, int, custom_hash> gp_h_table;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ord_set;

// because comp fns require strict ordering less_equal will FLIP upper_bound and lower_bound for ord_multiset
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ord_multiset;
// Also for some reason ord_multiset just gives an error on my compiler "msys64/mingw64/include/c++/10.3.0"
// Works on CF servers tho, (G++17 9.2.0)

const int dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0};
const long double eps = 1e-7;
const ld PI = 3.14159265358979323846L;
const ll lINF = (ll)1e18L + 007;
const int MOD = 1e9 + 007;
const int iINF = 1e9 + 007;
// const int MOD = 998244353;
// ll MOD;

// const int tasz = 1e6 + 007;
ll a[1007][1007];
bool vis[1007][1007];
int cnt;

void dfs(int x, int y) {
    vis[x][y] = 1;
    cnt++;
    f0r(i, 4) {
        if (a[x][y] & (1 << i)) continue;
        if (!vis[x + dx[i]][y + dy[i]]) {
            dfs(x + dx[i], y + dy[i]);
        }
    }
}

void solve() {
    int n, m;
    vi ans;
    cin >> n >> m;
    f0r(i, n) f0r(j, m) cin >> a[i][j];
    f0r(i, n) f0r(j, m) if (!vis[i][j]) cnt = 0, dfs(i, j), ans.pb(cnt);
    soR(ans);
    ao(ans, sz(ans));
}

int main() {

#ifdef asr
    auto begin = chrono::high_resolution_clock::now();
#endif

    vamos;

    fix(15);

    int TT = 1;
    // cin >> TT;
    f1r(TC, 1, TT)
        solve();

#ifdef asr
    auto end = chrono::high_resolution_clock::now();
    cout << setprecision(2) << fixed;
    cout << "Execution time: " << chrono::duration_cast<chrono::duration<double>>(end - begin).count() * 1000 << " ms" << endl;
#endif

    return 0;
}