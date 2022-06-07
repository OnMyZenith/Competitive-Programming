/* Author: OnMyZenith - https://github.com/OnMyZenith */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef asr_debug
#include "dbg.hpp"
#else
#define dbg(...) 007
#endif

// PBDS Ordered set
#include <bits/extc++.h>
using namespace __gnu_pbds;

template <class T> using ord_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve() {
    int n; cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; i++) cin >> p[i], p[i]--;


    vector<vector<pair<int, int>>> num_pos_power(n, vector<pair<int, int>> (n, {0, 0}));
    ord_set<int> s;
    for (int pos = 0; pos < n; pos++) {
        for (int num = 0; num < n; num++) {
            int smaller_to_left = (int)s.order_of_key(num);
            int larger_to_right = (n - num) - (pos - smaller_to_left) - (p[pos] > num);
            num_pos_power[num][pos] = {smaller_to_left, larger_to_right};
        }
        s.insert(p[pos]);
    }



    ll res = 0;
    for (int b = 1; b < n; b++) {
        for (int c = n - 2; c > b; c--) {
            res += (ll)(num_pos_power[p[c]][b].first) * (n - c - 1 - num_pos_power[p[b]][c].second);
        }
    }
    cout << res << '\n';


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