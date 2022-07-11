/* Author: OnMyZenith - https://github.com/OnMyZenith */
#include <bits/stdc++.h>
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
        bool _lset = 0, _rset = 0;
        for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
            if (l & 1) {
                if(_lset) {
                    lv = fun(lv, v[l++]);
                } else lv = v[l++], _lset = 1;
            }
            if (r & 1) {
                if (_rset) {
                    rv = fun(rv, v[--r]);
                } else rv = v[--r], _rset = 1;
            }
        }
        if(!_lset) return NEUTRAL_VAL;
        return fun(lv, rv);
    }
};

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << setprecision(15) << fixed;

    int n, q; cin >> n >> q;
    vector<array<ll, 2>> a(n); // {largest prefix, whole sum}
    for (int i = 0; i < n; i++) {
        cin >> a[i][1];
        a[i][0] = a[i][1] > 0 ? a[i][1] : 0;
    }
    auto fun = [](const array<ll, 2> &x, const array<ll, 2> &y) -> array<ll, 2> {
        return {max(x[1] + y[0], x[0]), x[1] + y[1]};
    };
    segtree<array<ll, 2>, decltype(fun)> tree(a, fun, {0, 0});

    while (q--) {
        int t; cin >> t;
        if(t == 1) {
            int k, u; cin >> k >> u; k--;
            tree.set(k, {(u > 0 ? u : 0), u});
        } else {
            int l, r; cin >> l >> r; l--;
            dbg(tree.query(l, r));
            cout << tree.query(l, r)[0] << '\n';
        }
    }

    return 0;
}