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

template <class T> using ord_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;


void solve() {
    int n, m; cin >> n >> m;
    vector<int> a(n);
    ord_set<pair<int, int>> s;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (s.empty() || -(*s.rbegin()).first > a[i]) {
            s.insert({-a[i], i});
        }
    }

    while (m--) {
        int id, d; cin >> id >> d; --id;

        int lo = -1, hi = (int)s.size() - 1;
        while (lo < hi) {
            int mid = (lo + hi + 1) / 2;
            auto &[_x, i] = *s.find_by_order(mid);
            if (i > id) hi = mid - 1;
            else lo = mid;
        }
        assert(lo >= 0);
        a[id] -= d;
        auto it = s.find_by_order(lo);
        if (it->second == id) {
            while (it != s.end() && -it->first >= a[id]) {
                it = s.erase(it);
            }
            s.insert({-a[id], id});
        } else {
            if (-it->first > a[id]) {
                ++it;
                while (it != s.end() && -it->first >= a[id]) {
                    it = s.erase(it);
                }
                s.insert({-a[id], id});
            }
        }
        cout << (int)s.size() << (m ? ' ' : '\n');
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
