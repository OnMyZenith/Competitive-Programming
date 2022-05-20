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

    int n, k; cin >> n >> k;
    vector<int> a(n), med(n - k + 1);
    ord_multiset<int> s;
    for (int i = 0, j = -k + 1; i < n; i++, j++) {
        cin >> a[i];
        s.insert(a[i]);
        if(j >= 0) {
            med[j] = *s.find_by_order((k + 1) / 2 - 1);
            auto it = s.upper_bound(a[j]);
            assert(*it == a[j]);
            s.erase(it);
        }
    }
    dbg(med);
    ll cost = 0;
    for (int i = 0; i < n; i++) {
        if(i < k) cost += abs(a[i] - med[0]);
        else {
            cout << cost << " ";
            cost += abs(a[i] - med[i - k + 1]) - abs(a[i - k] - med[i - k]);
            ll diff = abs(med[i - k + 1] - med[i - k]);
            if (k % 2 == 0 && !((a[i] >= med[i - k + 1] && a[i - k] >= med[i - k]) || (a[i] <= med[i - k + 1] && a[i - k] <= med[i - k]))) {
                cost -= diff;
            }
        }
    }
    cout << cost << '\n';

    return 0;
}