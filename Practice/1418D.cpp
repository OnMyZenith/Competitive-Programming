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
template <class T> using pqdec = std::priority_queue<T>;
template <class T> using pqinc = std::priority_queue<T, vector<T>, greater<T>>;

template <class T, class U> bool erase(T &t, U u) {
    auto it = t.find(u);
    if (it == end(t)) return false;
    t.erase(it); return true;
}

int main() {
    vamos;

    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    multiset<int> diff;
    for (int i = 0; i < n - 1; i++) {
        diff.insert(a[i + 1] - a[i]);
    }
    ord_set<int> s(a.begin(), a.end());
    cout << *s.rbegin() - *s.begin() - (diff.empty() ? 0 : (*--diff.end())) << '\n';
    while(q--) {
        int add, x; cin >> add >> x;
        if(add){
            s.insert(x);
            int i = (int)s.order_of_key(x);
            if((int)s.size() == 1) {cout << "0\n"; continue;}
            if(!i) {
                diff.insert(*s.find_by_order(i + 1) - x);
            } else if ((int)s.size() == i + 1) {
                diff.insert(x - *s.find_by_order(i - 1));
            } else {
                int nxt = *s.find_by_order(i + 1), prev = *s.find_by_order(i - 1);
                erase(diff, nxt - prev);
                diff.insert(nxt - x);
                diff.insert(x - prev);
            }
        } else {
            if((int)s.size() == 1) {cout << "0\n"; s.clear(); continue;}
            int i = (int)s.order_of_key(x);
            if(!i) {
                erase(diff, *s.find_by_order(i + 1) - x);
            } else if ((int)s.size() == i + 1) {
                erase(diff, x - *s.find_by_order(i - 1));
            } else {
                int nxt = *s.find_by_order(i + 1), prev = *s.find_by_order(i - 1);
                diff.insert(nxt - prev);
                erase(diff, nxt - x);
                erase(diff, x - prev);
            }
            s.erase(x);
        }
        if(diff.empty()) {
            cout << *s.rbegin() - *s.begin() << '\n';
            continue;
        }
        cout << *s.rbegin() - *s.begin() - (*--diff.end()) << '\n';
    }
    return 0;
}