#include <bits/stdc++.h>
using namespace std;

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
#define ft front()
#define bk back()
#define rsz resize
#define ass assign
#define eq equal_range
#define ts to_string
#define nl '\n'

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define sor(v) sort(all(v))
#define soR(v) sort(rall(v))
#define sz(v) ((int)v.size())
#define bg(v) v.begin()

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

template <class T, class U>
bool erase(T &t, const U &u) {
    auto it = t.find(u);
    if (it == end(t)) return false;
    else
        t.erase(it);
    return true;
}
template <class T, class U>
T fstTrue(T lo, T hi, U f) {
    ++hi, assert(lo <= hi);
    while (lo < hi) {
        T mid = lo + (hi - lo) / 2;
        f(mid) ? hi = mid : lo = mid + 1;
    }
    return lo;
}
template <class T, class U>
T lstTrue(T lo, T hi, U f) {
    --lo, assert(lo <= hi);
    while (lo < hi) {
        T mid = lo + (hi - lo + 1) / 2;
        f(mid) ? lo = mid : hi = mid - 1;
    }
    return lo;
}

template <class Fun>
class y_combinator_result {
    Fun fun_;

public:
    template <class T>
    explicit y_combinator_result(T &&fun) : fun_(std::forward<T>(fun)) {}
    template <class... Args>
    decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};
template <class Fun>
decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }

constexpr int pct(int x) { return __builtin_popcount(x); }                                  // # of bits set
constexpr int log_2(int x) { return x ? (8 * (int)sizeof(x)) - 1 - __builtin_clz(x) : -1; } // Floor of log_2(x); index of highest 1-bit
constexpr int next_pow_2(int x) { return x > 0 ? 1 << log_2(2 * x - 1) : 0; }               // 16->16, 13->16, (x<=0)->0
constexpr int log_2_ceil(int x) { return log_2(x) + int(__builtin_popcount(x) != 1); }      // Ceil of log_2(x);

void solve() {
    
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << setprecision(15) << fixed;

    int TT = 1;
    cin >> TT;
    while(TT--)
        solve();

    return 0;
}