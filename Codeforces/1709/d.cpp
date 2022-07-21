/* Author: OnMyZenith - https://github.com/OnMyZenith */
#include "bits/stdc++.h"
using namespace std;
using ll = long long;

#ifdef asr_debug
#include "dbg.hpp"
#else
#define dbg(...) 007
#endif

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
        for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
            if (l & 1) lv = fun(lv, v[l++]);
            if (r & 1) rv = fun(rv, v[--r]);
        }
        return fun(lv, rv);
    }
};


void solve() {
    int n, m; cin >> n >> m;
    vector<int> a(m);
    for (auto &e : a) {
        cin >> e;
    }
    auto _max = [](auto &i, auto &j) {
        return max(i, j);
    };
    segtree<int, decltype(_max)> tree(a, _max, 0);
    int q; cin >> q;
    while (q--) {
        int x1, y1, x2, y2, k; cin >> x1 >> y1 >> x2 >> y2 >> k;
        swap(x1, y1);
        swap(x2, y2);
        x1--, x2--;
        bool pass = ((y2 - y1) % k == 0) && ((x2 - x1) % k == 0);
        int y3 = y1 + ((n - y1) / k) * k;
        int y4 = y2 + ((n - y2) / k) * k;
        dbg(pass, y3, y4);
        if (pass) {
            pass &= tree.query(min(x1, x2), max(x1, x2) + 1) < y3;
            dbg(tree.query(min(x1, x2), max(x1, x2) + 1));
        }
        cout << (pass ? "YES" : "NO") << '\n';
    }




}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << setprecision(15) << fixed;

    int TT = 1;
    // cin >> TT;
    while(TT--) {
        solve();
    }

    return 0;
}
