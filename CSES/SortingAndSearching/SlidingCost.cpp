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

    ll n, k; cin >> n >> k;
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
    ll med = a[*left.begin()];
    ll sleft = 0;
    ll sright = 0;
    for (auto &u : left) {
        sleft += a[u];
    }
    for (auto &u : right) {
        sright += a[u];
    }
    cout << ((k + 1) / 2) * med - sleft + sright - med * (k / 2);
    for (int i = k; i < n; i++) {

        auto itl = left.begin();
        auto itr = right.begin();
        if(a[i - k] <= a[*itl]) {
            auto f = left.find(i - k);
            left.erase(f);
            sleft -= a[i - k];
            if(!(k & 1)) {
                left.insert(*itr);
                sleft += a[*itr];
                sright -= a[*itr];
                right.erase(itr);
            }
        } else {
            auto f = right.find(i - k);
            right.erase(f);
            sright -= a[i - k];
            if(k & 1) {
                right.insert(*itl);
                sleft -= a[*itl];
                sright += a[*itl];
                left.erase(itl);
            }
        }

        itl = left.begin();
        if(a[i] < a[*itl]) {
            left.insert(i);
            sleft += a[i];
            if(!(k & 1)) {
                itl = left.begin();
                right.insert(*itl);
                sleft -= a[*itl];
                sright += a[*itl];
                left.erase(itl);
            }
        } else {
            right.insert(i);
            sright += a[i];
            if(k & 1) {
                itr = right.begin();
                left.insert(*itr);
                sleft += a[*itr];
                sright -= a[*itr];
                right.erase(itr);
            }
        }

        med = a[*left.begin()];
        cout << " " << ((k + 1) / 2) * med - sleft + sright - med * (k / 2);
    }
    cout << '\n';
    return 0;
}