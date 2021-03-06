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

template <typename T_vector> void ov(const T_vector &v, bool add_one = false, int start = -1, int end = -1) {
    if (start < 0) start = 0;
    if (end < 0) end = int(v.size());

    for (int i = start; i < end; i++)
        cout << v[i] + (add_one ? 1 : 0) << " \n"[i == end - 1];
}

struct range {
    int l, r, idx;
};

int main() {
    vamos;

    int n; cin >> n;
    vector<range> R(n);
    vector<pair<int, int>> l(n), r(n);
    for (int i = 0; i < n; i++) {
        R[i].idx = i;
        cin >> R[i].l >> R[i].r;
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
    ov(contains);
    ov(contained_in);

    return 0;
}