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
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    auto _max = [](auto &a1, auto &a2) -> auto {
        return max(a1, a2);
    };
    segtree<int, decltype(_max)> monster(a, _max, 0);

    int m; cin >> m;
    vector<array<int, 2>> p(m);
    int MXP = 0;
    for (auto &[f, s] : p) {
        cin >> f >> s;
        MXP = max(MXP, f);
    }
    if (MXP < *max_element(a.begin(), a.end())) {
        cout << "-1\n";
        return;
    }
    auto _cmp_arr2 = [](auto &p1, auto &p2) -> bool {
        return p1[0] < p2[0];
    };
    sort(p.begin(), p.end(), _cmp_arr2);
    vector<int> suff_max(m + 1);
    for (int i = m - 1; i >= 0; i--) {
        suff_max[i] = max(suff_max[i + 1], p[i][1]);
    }

    int ans = 0;
    for (int i = 0; i < n;) {
        int lo = 1, hi = min(suff_max[0], n - i);
        while (lo < hi) {
            int mid = (lo + hi + 1) / 2;
            int need = monster.query(i, i + mid);
            int idx = int(lower_bound(p.begin(), p.end(), array<int, 2>{need, -1}, _cmp_arr2) - p.begin());
            if (suff_max[idx] < mid) hi = mid - 1;
            else lo = mid;
        }
        ans++;
        i += lo;
    }
    cout << ans << '\n';
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