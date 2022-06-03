/* Author: OnMyZenith - https://github.com/OnMyZenith */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef asr_debug
#include "dbg.hpp"
#else
#define dbg(...) 007
#endif

#include <bits/extc++.h>
using namespace __gnu_pbds;

template <class T> using ord_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << setprecision(15) << fixed;

    int n, q; cin >> n >> q;
    vector<int> p(n);
    for (int i = 0; i < n; i++) cin >> p[i];
    ord_multiset<int> s(p.begin(), p.end());

    while (q--) {
        char type; cin >> type;
        if (type == '!') {
            int idx, x; cin >> idx >> x; idx--;
            auto it = s.upper_bound(p[idx]);
            s.erase(it); s.insert(x); p[idx] = x;
            continue;
        }
        int a, b; cin >> a >> b;
        cout << int(s.order_of_key(b + 1) - s.order_of_key(a)) << '\n';
    }

    return 0;
}