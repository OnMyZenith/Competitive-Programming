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


// B. Chess Tournament
// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output
// A chess tournament will be held soon, where n chess players will take part. Every participant will play one game against every other participant. Each game ends in either a win for one player and a loss for another player, or a draw for both players.

// Each of the players has their own expectations about the tournament, they can be one of two types:

// a player wants not to lose any game (i. e. finish the tournament with zero losses);
// a player wants to win at least one game.
// You have to determine if there exists an outcome for all the matches such that all the players meet their expectations. If there are several possible outcomes, print any of them. If there are none, report that it's impossible.

// Input
// The first line contains a single integer t (1≤t≤200) — the number of test cases.

// The first line of each test case contains one integer n (2≤n≤50) — the number of chess players.

// The second line contains the string s (|s|=n; si∈{1,2}). If si=1, then the i-th player has expectations of the first type, otherwise of the second type.

// Output
// For each test case, print the answer in the following format:

// In the first line, print NO if it is impossible to meet the expectations of all players.

// Otherwise, print YES, and the matrix of size n×n in the next n lines.

// The matrix element in the i-th row and j-th column should be equal to:

// +, if the i-th player won in a game against the j-th player;
// -, if the i-th player lost in a game against the j-th player;
// =, if the i-th and j-th players' game resulted in a draw;
// X, if i=j.
// Example
// inputCopy
// 3
// 3
// 111
// 2
// 21
// 4
// 2122
// outputCopy
// YES
// X==
// =X=
// ==X
// NO
// YES
// X--+
// +X++
// +-X-
// --+X





const ll tasz = 1e6 + 7;




void solve() {
    ll n;
    cin >> n;
    string s;
    cin >> s;
    vl v;
    f0r(i,n){
        if(s[i]=='2'){
            v.pb(i);
        }
    }
    if(sz(v)==0){
        cout << "YES\n";
        f0r(i,n) f0r(j,n) cout<<"=X"[i==j]<<(j==n-1?"\n":"");
        return;
    }
    if(sz(v)<=2){
        cout << "NO\n";
        return;
    }
    string mat[n];
    f0r(i,n)f0r(j,n)mat[i]+='=';
    f0r(i,n)mat[i][i]='X';
    mat[v[sz(v)-1]][v[0]]='+';
    mat[v[0]][v[sz(v)-1]]='-';
    f0r(i,sz(v)-1){
        mat[v[i]][v[i+1]]='+';
        mat[v[i+1]][v[i]]='-';
    }
    cout << "YES\n";
    f0r(i,n)cout<<mat[i]<<'\n';
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