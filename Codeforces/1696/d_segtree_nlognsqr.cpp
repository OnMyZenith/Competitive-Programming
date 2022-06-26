/* Author: OnMyZenith - https://github.com/OnMyZenith */
#include "bits/stdc++.h"
using namespace std;
using ll = long long;

#ifdef asr_debug
#include "dbg.hpp"
#else
#define dbg(...) 007
#endif

template <class T> bool ckmin(T &x, const T &y) { return (y < x) ? (x = y, 1) : 0; }
template <class T> bool ckmax(T &x, const T &y) { return (y > x) ? (x = y, 1) : 0; }
template <class T, class Fun> struct segtree {
    int N; vector<T> v; Fun fun; T NEUTRAL_VAL;

    // v i.e. the tree is indexed 1 based & arr i.e. input data is indexed 0 based.
    segtree(vector<T> &arr, Fun &_fun, T _NEUTRAL_VAL) : fun(_fun), NEUTRAL_VAL(_NEUTRAL_VAL) {
        N = 1; while (N < (int)arr.size()) N <<= 1;
        v.assign(N << 1, NEUTRAL_VAL);
        for (int i = 0; i < ((int)arr.size()); i++) v[N + i] = arr[i];
        for (int i = N; --i;) v[i] = fun(v[i << 1], v[i << 1 | 1]);
    }

    // idx is 0 based
    void set(int idx, T x) {
        for (v[idx += N] = x; idx >>= 1;)
            v[idx] = fun(v[idx << 1], v[idx << 1 | 1]);
    }
    
    // idx is 0 based
    void add(int idx, T x) {
        for (v[idx += N] += x; idx >>= 1;)
            v[idx] = fun(v[idx << 1], v[idx << 1 | 1]);
    }

    // [l, r) Half-Intervals
    T query(int l, int r) {
        T lv = NEUTRAL_VAL, rv = NEUTRAL_VAL;
        // dbg(l, r);
        for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
            if (l & 1) lv = fun(lv, v[l++]);
            if (r & 1) rv = fun(rv, v[--r]);
        }
        return fun(lv, rv);
    }
    void print() {
    #ifdef asr_debug
            int nodes = 1, spaces = 2 * N, idx = 1;
            while (idx < 2 * N) {
                for (int j = 0; j < nodes; j++) {
                    cout << setw(j ? 2 * spaces : spaces);
                    if (v[idx] != NEUTRAL_VAL) cout << (v[idx]); else cout << ('_');
                    idx++;
                }
                cout << '\n'; nodes *= 2; spaces /= 2;
            }
            for (int k = 0; k < 2 * 2 * N; k++) cout << "-\n"[k == 2 * 2 * N - 1];
    #endif
        }
    
};
// Check result <= hi
template <class T, class U> T ft(T lo, T hi, U f) {
    ++hi, assert(lo <= hi);
    while (lo < hi) {
        T mid = lo + (hi - lo) / 2;
        // dbg(mid, lo, hi);
        f(mid) ? hi = mid : lo = mid + 1;
    }
    return lo;
}

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    if (n == 1) {
        cout << 0 << '\n';
        return;
    }
    auto _min = [](int &i, int &j) -> int {return min(i, j);};
    auto _max = [](int &i, int &j) -> int {return max(i, j);};
    segtree<int, decltype(_min)> minTree(a, _min, int(1e9 + 7));
    segtree<int, decltype(_max)> maxTree(a, _max, 0);
    // minTree.print();
    // maxTree.print();
    // dbg(maxTree.v);
    vector<int> adj(n);
    for (int i = 0; i < n; i++) {
        int lim = max(ft(i, n - 1, [&](int idx) -> bool {return minTree.query(i, idx + 1) < a[i];}),
                     ft(i, n - 1, [&](int idx) -> bool {return maxTree.query(i, idx + 1) > a[i];})) - 1;
        int mx = maxTree.query(i, lim + 1);
        int mn = minTree.query(i, lim + 1);
        if (mx > a[i]) {
            adj[i] = ft(0, lim, [&](int idx) -> bool {return maxTree.query(i, idx + 1) >= mx;});
        } else {
            adj[i] = ft(0, lim, [&](int idx) -> bool {return minTree.query(i, idx + 1) <= mn;});
        }
    }
    dbg(adj);
    queue<pair<int, int>> q; q.push({0, 0});
    vector<bool> enque(n); enque[0] = 1;
    while (!q.empty()) {
        auto [v, dis] = q.front(); q.pop();
        if (v == n - 1) {
            cout << dis << '\n';
            return;
        }
        if (adj[v] > 0 && adj[v] < n && !enque[adj[v]]) {
            q.push({adj[v], dis + 1});
            enque[adj[v]] = 1;
        }
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << setprecision(15) << fixed;

    int TT = 1;
    cin >> TT;
    while(TT--) {
        solve();
    }

    return 0;
}