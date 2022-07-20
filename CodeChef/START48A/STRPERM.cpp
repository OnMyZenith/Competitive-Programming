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
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> a(m);
    vector<int> cushion(n + 1);
    for (auto &[x, y] : a) {
        cin >> x >> y;
        cushion[x] = n - y;
    }

    auto _min = [](auto &x, auto &y) {
        return min(x, y);
    };
    segtree<int, decltype(_min)> tree(cushion, _min, n + 2);
    vector<int> res;
    bool fail = 0;
    for (int i = 0; i < n && !fail; i++) {
        int have = (int)res.size();
        int lo = 0, hi = n;
        while (lo < hi) {
            int mid = (lo + hi + 1) / 2;
            if (tree.query(mid, hi + 1) <= have) {
                lo = mid;
            } else {
                hi = mid - 1;
            }
        }
        if (lo == 0) {
            fail = 1;
            break;
        }
        res.push_back(lo);
        tree.set(lo, n + 2);
    }
    reverse(res.begin(), res.end());
    if ((int)res.size() == n && !fail) {
        for (int i = 0; i < n; i++) cout << res[i] << " \n"[i == n - 1];
    } else {
        cout << "-1\n";
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
