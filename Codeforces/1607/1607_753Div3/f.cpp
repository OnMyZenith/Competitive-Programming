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

template <typename X, typename Y>
X &remin(X &x, const Y &y) { return x = (y < x) ? y : x; }
template <typename X, typename Y>
X &remax(X &x, const Y &y) { return x = (x < y) ? y : x; }
template <typename X, typename Y>
bool ckmin(X &x, const Y &y) { return (y < x) ? (x = y, 1) : 0; }
template <typename X, typename Y>
bool ckmax(X &x, const Y &y) { return (x < y) ? (x = y, 1) : 0; }

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

// The robot is located on a checkered rectangular board of size n×m (n rows, m columns). The rows in the board are numbered from 1 to n from top to bottom, and the columns — from 1 to m from left to right.

// The robot is able to move from the current cell to one of the four cells adjacent by side.

// Each cell has one of the symbols 'L', 'R', 'D' or 'U' written on it, indicating the direction in which the robot will move when it gets in that cell — left, right, down or up, respectively.

// The robot can start its movement in any cell. He then moves to the adjacent square in the direction indicated on the current square in one move.

// If the robot moves beyond the edge of the board, it falls and breaks.
// If the robot appears in the cell it already visited before, it breaks (it stops and doesn't move anymore).
// Robot can choose any cell as the starting cell. Its goal is to make the maximum number of steps before it breaks or stops.

// Determine from which square the robot should start its movement in order to execute as many commands as possible. A command is considered successfully completed if the robot has moved from the square on which that command was written (it does not matter whether to another square or beyond the edge of the board).

// Input
// The first line contains an integer t (1≤t≤10000) — the number of test cases in the test.

// Each test case's description is preceded by a blank line. Next is a line that contains integers n and m (1≤n≤2000; 1≤m≤2000) — the height and width of the board. This line followed by n lines, the i-th of which describes the i-th line of the board. Each of them is exactly m letters long and consists of symbols 'L', 'R', 'D' and 'U'.

// It is guaranteed that the sum of sizes of all boards in the input does not exceed 4⋅106.

// Output
// For each test case, output three integers r, c and d (1≤r≤n; 1≤c≤m; d≥0), which denote that the robot should start moving from cell (r,c) to make the maximum number of moves d. If there are several answers, output any of them.

// Example
// inputCopy
// 7

// 1 1
// R

// 1 3
// RRL

// 2 2
// DL
// RU

// 2 2
// UD
// RU

// 3 2
// DL
// UL
// RU

// 4 4
// RRRD
// RUUD
// URUD
// ULLR

// 4 4
// DDLU
// RDDU
// UUUU
// RDLD
// outputCopy
// 1 1 1
// 1 1 3
// 1 1 4
// 2 1 3
// 3 1 5
// 4 3 12
// 1 1 4

ll n, m;
ll res;
// dfs
ll dfs(int x, int y, int &cnt, string *board) {
    if (x < 0 || x >= n || y < 0 || y >= m || board[x][y] == '#') return cnt;
    char t = board[x][y];
    board[x][y] == '#';
    cnt++;
    if (t == 'L') {
        dfs(x - 1, y, cnt, board);
    } else if (t == 'R') {
        dfs(x + 1, y, cnt, board);
    } else if (t == 'D') {
        dfs(x, y + 1, cnt, board);
    } else if (t == 'U') {
        dfs(x, y - 1, cnt, board);
    }
}

void solve() {
    res = 0;
    ll x, y;
    cin >> n >> m;
    string board[n];
    f0r(i, n) cin >> board[i];
    f0r(i, n) f0r(j, m) {
        int cnt = 0;
        dfs(i, j, cnt, board);
        if(ckmax(res, cnt))x=i,y=j;
    }cout<<x<<" "<<y<<" "<<res<<'\n';
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