/* Author: OnMyZenith - https://github.com/OnMyZenith */
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
#define int ll
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
// struct segtreep {
//     int N; vector<pair<int, int>> v; pair<int, int> NEUTRAL_VAL = {0, 0};

//     // v i.e. the tree is indexed 1 based & arr i.e. input data is indexed 0 based.
//     segtreep(vector<pair<int, int>> &arr, pair<int, int> _NEUTRAL_VAL) : NEUTRAL_VAL(_NEUTRAL_VAL) {
//         N = 1; while (N < (int)arr.size()) N <<= 1;
//         v.assign(N << 1, NEUTRAL_VAL);
//         for (int i = 0; i < ((int)arr.size()); i++) v[N + i] = arr[i];
//         for (int i = N; --i;) {
//             v[i].first = max(v[i << 1].first + v[i << 1 | 1].second, v[i << 1].second + v[i << 1 | 1].first);
//         }
//     }

//     int query(int l, int r) {
//         if (l + 1 == r) 
//     }

//     // [l, r) Half-Intervals
//     T query(int l, int r) {
//         T lv = NEUTRAL_VAL, rv = NEUTRAL_VAL;
//         for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
//             if (l & 1) lv = fun(lv, v[l++]);
//             if (r & 1) rv = fun(rv, v[--r]);
//         }
//         return fun(lv, rv);
//     }
// };

const int inf = 1e9;

void solve() {
    int n, q; cin >> n >> q;

    // center, left, right
    vector<array<int, 3>> dp(n);
    vector<pair<int, int>> onestr(n);

    auto res = [&](int m, string &s) -> vector<int> {

        vector<int> dp1(m + 1, -1);
        dp1[0] = 0;
        vector<int> cnt(m + 1);
        for (int i = 1; i <= m; i++) {
            cnt[i] = cnt[i - 1] + (s[i - 1] == '1' ? 1 : -1);
            ckmax(dp1[i], cnt[i]);
        }
        return dp1;
    };

    for (int i = 0, m; i < n; i++) {
        cin >> m;
        string s, r;
        cin >> s;

        int best = 0, curr = 0;
        for (int j = 0; j < m; j++) {
            curr += (s[j] == '1' ? 1 : -1);
            ckmax(best, curr);
            ckmax(curr, 0ll);
        }
        onestr[i] = {best, i};




        r = s;
        reverse(r.begin(), r.end());
        
        auto dps = res(m, s);
        auto dpr = res(m, r);
        int l = *max_element(dps.begin(), dps.end()), ri = *max_element(dpr.begin(), dpr.end());
        int c = dps[m];
        l -= max(c, 0ll);
        ri -= max(c, 0ll);
        dp[i] = {c, l, ri};
    }

    vector<ll> pre(n + 1);
    vector<pair<int, int>> _l(n), _r(n);

    for (int i = 0; i < n; i++) _l[i] = {max(dp[i][1], 0ll), i}, _r[i] = {max(dp[i][2], 0ll), i};
    for (int i = 0; i < n; i++) pre[i + 1] = pre[i] + max(dp[i][0], 0ll);

    auto _max = [](pair<int, int> &x, pair<int, int> &y) {
        if (x.first > y.first) return x;
        return y;
    };

    dbg(dp);
    segtree<pair<int, int> , decltype(_max)> left(_l, _max, {-inf, -1}), right(_r, _max, {-inf, -1}), mid(onestr, _max, {-inf, -1});
    while (q--) {
        int l, r; cin >> l >> r; l--;
        dbg(l, r, q);
        ll ans = pre[r] - pre[l];

        dbg(ans);
        auto [lres, lidx] = left.query(l, r);
        auto [rres, ridx] = right.query(l, r);
        
        if (pre[lidx])

        dbg(lres, lidx);
        dbg(rres, ridx);
        if (ridx == lidx) {
            ll ex1 = max(lres, 0ll);
            auto [rres1, ridx1] = right.query(l, ridx);
            auto [rres2, ridx2] = right.query(ridx + 1, r);
            ex1 += max(max(rres1, rres2), 0ll);

            ll ex2 = max(rres, 0ll);
            auto [lres1, lidx1] = left.query(l, ridx);
            auto [lres2, lidx2] = left.query(ridx + 1, r);
            ex2 += max(max(lres1, lres2), 0ll);
            dbg(ex1, ex2);
            ans += max(ex1, ex2);
            // if (lres > rres) {
            //     ans += max(lres, 0ll);
            //     auto [rres1, ridx1] = right.query(l, ridx);
            //     auto [rres2, ridx2] = right.query(ridx + 1, r);
            //     rres = max(rres1, rres2);
            //     ans += max(rres, 0ll);
            // } else if (lres < rres) {
            //     ans += max(rres, 0ll);
            //     auto [lres1, lidx1] = left.query(l, ridx);
            //     auto [lres2, lidx2] = left.query(ridx + 1, r);
            //     lres = max(lres1, lres2);
            //     ans += max(lres, 0ll);
            // } else {
            //     ans += max(lres, 0ll);
            //     auto [rres1, ridx1] = right.query(l, ridx);
            //     auto [rres2, ridx2] = right.query(ridx + 1, r);
            //     rres = max(rres1, rres2);
            //     auto [lres1, lidx1] = left.query(l, ridx);
            //     auto [lres2, lidx2] = left.query(ridx + 1, r);
            //     lres = max(lres1, lres2);
            //     ans += max(max(rres, lres), 0ll);
            // }
            // ckmax(rres, lres);
        } else {
            ans += max(lres, 0ll);
            ans += max(rres, 0ll);
        }

        auto [_ans, _id] = mid.query(l, r);

        dbg(pre[r] - pre[l], rres);
        cout << max(ans, (ll)_ans) << '\n';
    }
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << setprecision(15) << fixed;

    int TT = 1;
    // cin >> TT;
    while(TT--) {
        solve();
    }

    return 0;
}
