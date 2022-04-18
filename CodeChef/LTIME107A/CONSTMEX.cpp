/* Author: OnMyZenith - https://github.com/OnMyZenith */
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
using ll = long long;

#define vamos ios_base::sync_with_stdio(false), cin.tie(nullptr), cout << setprecision(15) << fixed;
#ifdef asr_debug
#include "dbg.hpp"
#else
#define dbg(...) 007
#endif

template <class T> using ord_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
/*
Source : https://codeforces.com/blog/entry/11080
Note on using less_equal as comparison function to use it as a multiset:
    _GLIBCXX_DEBUG must not be defined, otherwise some internal check will fail.
    find will always return end.
    lower_bound works like upper_bound in normal set (to return the first element > it)
    upper_bound works like lower_bound in normal set (to return the first element >= it)
    find_by_order and order_of_key works properly (unlike the 2 functions above).
*/
template <class T> using ord_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
// template <typename T_vector> void ov(const T_vector &v, bool add_one = false, int start = -1, int end = -1) {
//     if (start < 0) start = 0;
//     if (end < 0) end = int(v.size());
 
//     for (int i = start; i < end; i++)
//         cout << v[i] + (add_one ? 1 : 0) << " \n"[i == end - 1];
// }
 
struct range {
    int l, r, idx;
};
 
long long cal(vector<pair<int, int>> &p) {
    dbg(p);
    int n = (int)p.size();
    if(n < 2) return 0;
    vector<range> R(n);
    vector<pair<int, int>> l(n), r(n);
    for (int i = 0; i < n; i++) {
        R[i].idx = i;
        // cin >> R[i].l >> R[i].r;
        R[i].l = p[i].first;
        R[i].r = p[i].second;
        l[i].first = R[i].l;
        r[i].first = R[i].r;
        l[i].second = r[i].second = i;
    }
    sort(l.begin(), l.end());
    sort(r.begin(), r.end(), [&](pair<int, int> i, pair<int, int> j){
        if(i.first != j.first) return i.first < j.first;
        return R[i.second].l > R[j.second].l;
    });
 
    ord_multiset<int> open, closed;
    vector<int> contained_in(n), contains(n);
    int i = 0, j = 0;
    while(i < n || j < n) {
        if(i < n && l[i].first < r[j].first) {
            open.insert(l[i].first); i++;
        } else {
            int idx = r[j].second, _l = R[idx].l;
            auto it = open.upper_bound(_l);
            dbg(open);
            open.erase(it);
            dbg(open);
            contained_in[idx] = int(open.order_of_key(_l + 1));
            contains[idx] = int((int)closed.size() - closed.order_of_key(_l));
            closed.insert(_l);
            j++;
        }
        dbg(open, closed);
    }
    // ov(contains);
    // ov(contained_in);
 
    return accumulate(contained_in.begin(), contained_in.end(), 0LL);
}

// Check result <= hi
template <class T, class U> T ft(T lo, T hi, U f) {
    ++hi, assert(lo <= hi);
    while (lo < hi) {
        T mid = lo + (hi - lo) / 2;
        f(mid) ? hi = mid : lo = mid + 1;
    }
    return lo;
}

// Check result >= lo
template <class T, class U> T lt(T lo, T hi, U f) {
    --lo, assert(lo <= hi);
    while (lo < hi) {
        T mid = lo + (hi - lo + 1) / 2;
        f(mid) ? lo = mid : hi = mid - 1;
    }
    return lo;
}


void solve() {
    int n;
    cin >> n;
    vector<int> a(n), suff(n), pre(n), tmp(n + 1);
    iota(tmp.begin(), tmp.end(), 0);
    set<int> not_seen(tmp.begin(), tmp.end()), ns;
    ns = not_seen;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        not_seen.erase(a[i]);
        pre[i] = *not_seen.begin();
    }
    not_seen = ns;
    for (int i = n - 1; i >= 0; i--) {
        not_seen.erase(a[i]);
        suff[i] = *not_seen.begin();
    }
    // vector<bool> pv(n), sv(n);
    // for (int i = 0; i < n; i++) {
    //     if (i) pv[i] = pre[i - 1] < a[i];
    //     if (i < n - 1) sv[i] = suff[i + 1] < a[i];
    // }
    // vector<int> pre_fin_v(n);
    // for (int i = 0; i < n; i++) pre_fin_v[i] = (i ? pre_fin_v[i - 1] : 0) + sv[i] && pv[i];
    // dbg(sv);
    // ll res = 0;
    // reverse(suff.begin(), suff.end());
    // vector<int> ri(n), le(n, -1);
    vector<pair<int, int>> fin;
    for (int i = 0; i < n; i++) {
        // if (pv[i]) {
            int r = lt(0, n - 1, [&](int m){
                return pre[m] < a[i];
            });
            int l = ft(0, n - 1, [&](int m){
                return suff[m] < a[i];
            });
            dbg(l, r, a[i]);
            if(l <= i && r >= i) {
                fin.push_back({l, r});
            }

            // le[i] = l;
            // ri[i] = r;
        // }
    }



    cout << cal(fin) << '\n';
}

int main() {
    vamos;

    int TT = 1;
    cin >> TT;
    while (TT--) {
        solve();
    }

    return 0;
}