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
    int n; cin >> n;
    auto q1 = [&](int idx) -> char{
        cout << "? 1 " << idx + 1 << endl;
        char c; cin >> c; return c;
    };
    auto q2 = [&](int l, int r) -> int{
        cout << "? 2 " << l + 1 << " " << r + 1 << endl;
        int c; cin >> c; return c;
    };

    vector<int> id(n, -1);
    id[0] = 0;
    ord_set<pair<int, int>> s; // pos_id;
    s.insert({0, 0});

    int curr = 0;
    for (int i = 1; i < n; i++) {
        int expect = 1;

        int size = (int)s.size();
        // if(q2(0, i) < (int)s.size() + 1) {
        //     s.insert({-i, ++curr});
        //     id[i] = curr;
        //     continue;
        // }

        int lo = 0, hi = size;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            expect = 1 + 1 + mid;
            auto [pos, _id] = *s.find_by_order(mid);
            int ncnt = q2(-pos, i);
            if (ncnt < expect) hi = mid;
            else lo = mid + 1;
        }
        dbg(lo);
        if (lo == size) {
            curr++;
            s.insert({-i, curr});
            id[i] = curr;
        } else {
            auto it = s.find_by_order(lo);
            id[i] = it->second;
            s.insert({-i, id[i]});
            s.erase(it);
        }
    }
    string fin;
    vector<char> decode(26);
    for (int i = 0; i < n; i++) {
        if(!decode[id[i]]) {
            char c = q1(i);
            decode[id[i]] = c;
        }
        fin += decode[id[i]];
    }
    dbg(id);
    dbg(decode);


    cout << "! " << fin << endl;



}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << setprecision(15) << fixed;

    int TT = 1;
    // cin >> TT;
    while(TT--) {
        solve();
    }

    return 0;
}