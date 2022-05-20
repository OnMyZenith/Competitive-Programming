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

Some more observations:
    erase(ord_mul_set.find(ele)); <-- doesn't work
    use this instead:
    auto it = ord_mul_set.upper_bound(ele); <-- actually gives lower_bound
    if(*it == ele) ord_mul_set.erase(it);
*/
template <class T> using ord_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;



int main() {
    vamos;

    int n, m, q; cin >> n >> m >> q;
    ord_set<int> s;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c; cin >> c;
            if (c == '*') s.insert(n * j + i);
        }
    }
    // dbg(s);
    while(q--) {
        int x, y; cin >> x >> y;
        int p = (--y * n) + --x;
        auto it = s.find(p);
        if(it == s.end()) s.insert(p);
        else s.erase(it);
        int l = (int)s.size();
        // dbg(s);
        cout << l - int(s.order_of_key(l)) << '\n';
    }

    return 0;
}