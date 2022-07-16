/* Author: OnMyZenith - https://github.com/OnMyZenith */
#include "bits/stdc++.h"
using namespace std;
using ll = long long;

#ifdef asr_debug
#include "dbg.hpp"
#else
#define dbg(...) 007
#endif


void solve() {
    int n; cin >> n;
    vector<int> a(n);
    vector<vector<int>> mp(n);
    for (int i = 0; i < n; i++) cin >> a[i], mp[--a[i]].push_back(i);

    vector<vector<int>> grps;
    multiset<int> s(a.begin(), a.end());
    while (!s.empty()) {
        vector<int> one_set;
        for (auto it = s.begin(); it != s.end();) {
            one_set.push_back(*it);
            it = s.upper_bound(*it);
        }
        vector<int> one_grp;
        for (auto &e : one_set) {
            auto it = s.find(e);
            assert(*it == e);
            s.erase(it);
            assert(!mp[e].empty());
            int idx = mp[e].back();
            mp[e].pop_back();
            one_grp.push_back(idx);
        }
        grps.push_back(one_grp);
    }

    for (auto &idx_grp : grps) {
        int m = (int)idx_grp.size();
        if (!m) continue;

        int tmp = a[idx_grp.front()];
        for (int i = 0; i < m - 1; i++) {
            a[idx_grp[i]] = a[idx_grp[i + 1]];
        }
        a[idx_grp[m - 1]] = tmp;
    }

    for (int i = 0; i < n; i++) cout << ++a[i] << " \n"[i == n - 1];
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
