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

    int n, k, med; cin >> n >> k;
    vector<int> a(n);
    ord_multiset<int> s;
    ll cost = 0;

    auto erase = [&](int x) {
        auto it = s.upper_bound(x);
        assert(*it == x);
        s.erase(it);
    };

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        s.insert(a[i]);
        if(i == k - 1) {
            med = *s.find_by_order((k + 1) / 2 - 1);
            for (int j = 0; j < k; j++) {
                cost += abs(a[j] - med);
            }
            cout << cost;
        } else if (i >= k) {
            erase(a[i - k]);

            int newmed = *s.find_by_order((k + 1) / 2 - 1);
            erase(a[i]);
            s.insert(a[i - k]);

            int lar = k - (int)s.order_of_key(newmed + 1);
            int smol = (int)s.order_of_key(newmed);
            erase(a[i - k]);
            s.insert(a[i]);
            dbg(med, newmed, lar, smol);
            cost += (ll) abs(newmed - med) * abs(lar - smol);
            cost += (abs(a[i] - newmed) ? abs(a[i] - newmed) - abs(newmed - med) : 0) - abs(a[i - k] - newmed);

            cout << " " << cost;
            med = newmed;
        }
    }
    cout << '\n';
    return 0;
}