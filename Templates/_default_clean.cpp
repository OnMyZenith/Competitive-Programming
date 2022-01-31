#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;

#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
// #pragma GCC optimize("Ofast")
#pragma GCC target("avx2")
#pragma GCC target("popcnt,lzcnt,bmi,bmi2,tune=native")

#define pb push_back
#define eb emplace_back
#define ff first
#define ss second
#define lb lower_bound
#define ub upper_bound
#define ins insert
#define rsz resize
#define ass assign
#define ts to_string
#define nl '\n'

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define sor(v) sort(all(v))
#define soR(v) sort(rall(v))
#define sz(v) ((int)v.size())

template <class T>
using V = vector<T>;
template <class T>
using Q = queue<T>;
template <class T, class U>
using P = pair<T, U>;
template <class T, size_t SZ>
using AR = array<T, SZ>;
template <class T>
using pqdec = std::priority_queue<T>;
template <class T>
using pqinc = std::priority_queue<T, V<T>, greater<T>>;

using ll = long long;
using db = double;
using ld = long double;
using ull = unsigned long long;
using str = string;

template <class T>
bool ckmin(T &x, const T &y) { return (y < x) ? (x = y, 1) : 0; }
template <class T>
bool ckmax(T &x, const T &y) { return (y > x) ? (x = y, 1) : 0; }
template <class T>
T cdiv(T &a, T &b) { return a / b + ((a ^ b) > 0 && a % b); }
template <class T>
T fdiv(T &a, T &b) { return a / b - ((a ^ b) < 0 && a % b); }
template <class T>
int lwb(V<T> &a, const T &b) { return int(lb(all(a), b) - bg(a)); }
template <class T>
int upb(V<T> &a, const T &b) { return int(ub(all(a), b) - bg(a)); }
template <class T>
void remDup(V<T> &v) { sort(all(v)), v.erase(unique(all(v)), end(v)); }
template <class T>
T pow(T a, ll b) { T r = 1; while (b) { if (b & 1) r *= a; b >>= 1; a *= a; } return r; }
const int MOD = 1e9 + 007; // 998244353;

void solve() {
    



}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << setprecision(15) << fixed;

    // prepareFact(_);
    int TT = 1;
    cin >> TT;
    while(TT--)
        solve();

    return 0;
}