/* Author: OnMyZenith - https://github.com/OnMyZenith */
#include "bits/stdc++.h"
using namespace std;
using ll = long long;

#ifdef asr_debug
#include "dbg.hpp"
#else
#define dbg(...) 007
#endif

#include <bits/extc++.h>
using namespace __gnu_pbds;

/*
Source : https://codeforces.com/blog/entry/11080
Note on using less_equal as comparison function to use it as a multiset:
    _GLIBCXX_DEBUG must not be defined, otherwise some internal check will fail.
    find will always return end.
    lower_bound works like upper_bound in normal set (to return the first element > it)
    upper_bound works like lower_bound in normal set (to return the first element >= it)
    find_by_order and order_of_key works properly (unlike the 2 functions above).

Some more observations:
    erase(ord_mul_set.find(ele)); <-- doesn't work
    use this instead:
    auto it = ord_mul_set.upper_bound(ele); <-- actually gives lower_bound
    if(*it == ele) ord_mul_set.erase(it);
*/
template <class T> using ord_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << setprecision(15) << fixed;

    int n; cin >> n;
    struct Point {
        int x1, y1, x2, y2;
        bool hor;
    };
    vector<Point> a(n);
    vector<array<int, 3>> top_down;
    for (int i = 0; i < n; i++) {
        auto &[x1, y1, x2, y2, hor] = a[i];
        cin >> x1 >> y1 >> x2 >> y2;
        if (y1 > y2) swap(y1, y2);
        if (x1 > x2) swap(x1, x2);
        hor = y1 == y2;
        top_down.push_back({y1, -int(!hor), i});
        if (!hor) {
            top_down.push_back({y2, 1, i});
        }
    }
    sort(top_down.begin(), top_down.end());
    ll ans = 0;
    ord_multiset<int> curr;
    for (int i = 0; i < (int)top_down.size(); i++) {
        auto &[y, beg_end, idx] = top_down[i];
        if (beg_end == -1) {
            curr.insert(a[idx].x1);
            continue;
        } else if (beg_end == 1) {
            auto it = curr.upper_bound(a[idx].x1);
            dbg(idx, a[idx].x1);
            assert(*it == a[idx].x1);
            curr.erase(it);
            continue;
        }
        auto loan = curr;
        for (int j = i + 1; j < (int)top_down.size() && (int)loan.size() >= 2; j++) {
            auto &[y_, beg_end_, idx_] = top_down[j];
            if (beg_end_ == -1) {
                continue;
            } else if (beg_end_ == 1) {
                if (a[idx_].y1 > a[idx].y1) continue;
                auto it = loan.upper_bound(a[idx_].x1);
                assert(*it == a[idx_].x1);
                loan.erase(it);
                continue;
            }
            int xl = max(a[idx].x1, a[idx_].x1), xr = min(a[idx].x2, a[idx_].x2);
            int cnt = max(int(loan.order_of_key(xr + 1) - loan.order_of_key(xl)), 0);
            ans += (ll) cnt * (cnt - 1) / 2;
        }
    }
    cout << ans << '\n';

    return 0;
}