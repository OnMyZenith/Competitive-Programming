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


int main() {
    vamos;

    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (auto &u : a) {
        cin >> u;
    }

    auto _less = [&](int i, int j) -> bool {
        return a[i] < a[j];
    };
    auto _greater = [&](int i, int j) -> bool {
        return a[i] > a[j];
    };

    multiset<int, decltype(_less)> right(_less);
    multiset<int, decltype(_greater)> left(_greater);

    for (int i = 0; i < (k + 1) / 2; i++) left.insert(i);

    for (int i = (k + 1) / 2; i < k; i++) {
        auto it = left.begin();
        if(a[i] < a[*it]) {
            right.insert(*it);
            left.erase(it);
            left.insert(i);
        } else right.insert(i);
    }
    dbg(left, right);

    cout << a[*left.begin()];
    for (int i = k; i < n; i++) {
        dbg(left, right);

        auto itl = left.begin();
        auto itr = right.begin();
        if(a[i - k] <= a[*itl]) {
            auto f = left.find(i - k);
            left.erase(f);

            if(!(k & 1)) {
                left.insert(*itr);
                right.erase(itr);
            }
        } else {
            auto f = right.find(i - k);
            right.erase(f);

            if(k & 1) {
                right.insert(*itl);
                left.erase(itl);
            }
        }

        // dbg(left, right);
        // assert((int)left.size() - (int)right.size() <= 1);
        // assert((int)left.size() - (int)right.size() >= 0);

        itl = left.begin();
        if(a[i] < a[*itl]) {
            left.insert(i);
            if(!(k & 1)) {
                itl = left.begin();
                right.insert(*itl);
                left.erase(itl);
            }
        } else {
            right.insert(i);
            if(k & 1) {
                itr = right.begin();
                left.insert(*itr);
                right.erase(itr);
            }
        }

        cout << " " << a[*left.begin()];
    }
    cout << '\n';
    return 0;
}








/* NOT Working priority queue implementation */

// template <class T> using pqdec = std::priority_queue<T>;
// template <class T> using pqinc = std::priority_queue<T, vector<T>, greater<T>>;

// int main() {
//     vamos;

//     int n, k; cin >> n >> k;
//     vector<int> a(n);
//     for (auto &u : a) {
//         cin >> u;
//     }
//     if(k == 1) {for (int i = 0; i < n; i++) cout << a[i] << " \n"[i == n - 1]; return 0;}

//     auto _less = [&](int i, int j) -> bool {
//         return a[i] < a[j];
//     };
//     auto _greater = [&](int i, int j) -> bool {
//         return a[i] > a[j];
//     };
//     std::priority_queue<int, vector<int>, decltype(_less)> lq(_less);
//     std::priority_queue<int, vector<int>, decltype(_greater)> rq(_greater);
//     int l = (k + 1) / 2, r = k / 2;

//     {
//         vector<int> _tmp(k); iota(_tmp.begin(), _tmp.end(), 0);
//         sort(_tmp.begin(), _tmp.end(), _less);
//         for (int i = 0; i < l; i++) {
//             lq.push(_tmp[i]);
//         }
//         for (int i = l; i < k; i++) {
//             rq.push(_tmp[i]);
//         }
//     }

//     // dbg(lq.top());
//     // auto tmp = lq;
//     // while(!tmp.empty()) dbg(tmp.top()), tmp.pop();

//     cout << a[lq.top()];
//     for (int i = k; i < n; i++) {

//         int lt = lq.top();
//         int rt = rq.top();
//         if(a[i - k] > a[lt]) {
//             r--;
//         } else {
//             l--;
//             while(rt <= i - k) rq.pop(), rt = rq.top();
//             lq.push(rt); l++;
//             rq.pop(); r--;
//         }
//         // dbg(l, r);

//         lt = lq.top();
//         while(lt <= i - k) lq.pop(), lt = lq.top();

//         if(a[i] < a[lt]) {
//             lq.push(i); l++;
//         } else {
//             rq.push(i); r++;
//         }

//         while (r < k / 2) {
//             lt = lq.top();
//             while(lt <= i - k) lq.pop(), lt = lq.top();
            
//             rq.push(lt); r++;
//             lq.pop(); l--;
//         }
//         while (r > k / 2) {
//             rt = rq.top();
//             while(rt <= i - k) rq.pop(), rt = rq.top();
            
//             lq.push(rt); l++;
//             rq.pop(); r--;
//         }
//         // dbg(l, r);
//         lt = lq.top();
//         while(lt <= i - k) lq.pop(), lt = lq.top();
//         cout << " " << a[lt];
//     }
//     cout << '\n';

//     return 0;
// }




/* Working ord_multiset implementation */

// template <class T> using ord_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// /*
// Source : https://codeforces.com/blog/entry/11080
// Note on using less_equal as comparison function to use it as a multiset:
//     _GLIBCXX_DEBUG must not be defined, otherwise some internal check will fail.
//     find will always return end.
//     lower_bound works like upper_bound in normal set (to return the first element > it)
//     upper_bound works like lower_bound in normal set (to return the first element >= it)
//     find_by_order and order_of_key works properly (unlike the 2 functions above).

// Some more observations:
//     erase(ord_mul_set.find(ele)); <-- doesn't work
//     use this instead:
//     auto it = ord_mul_set.upper_bound(ele); <-- actually gives lower_bound
//     if(*it == ele) ord_mul_set.erase(it);
// */
// template <class T> using ord_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;


// int main() {
//     vamos;

//     int n, k; cin >> n >> k;
//     vector<int> a(n);
//     ord_multiset<int> s;
//     for (int i = 0, j = -k + 1; i < n; i++, j++) {
//         cin >> a[i];
//         s.insert(a[i]);
//         if(j >= 0) {
//             cout << *s.find_by_order(k / 2 - !(k & 1)) << " \n"[i == n - 1];
//             auto it = s.upper_bound(a[j]);
//             assert(*it == a[j]);
//             s.erase(it);
//         }
//     }

//     return 0;
// }