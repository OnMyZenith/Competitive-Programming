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
    vector<pair<int, int>> a(n);
    vector<bool> th(n, 1);
    multiset<int> l, r;
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
        a[i].first--, a[i].second--;
        if (a[i].first <= i && i <= a[i].second) {
            th[i] = 0;
        }
        l.insert(a[i].first);
        r.insert(a[i].second);
    }
    vector<int> res;
    for (int i = 0; i < n; i++) {
        if (th[i]) {
            l.erase(l.find(a[i].first));
            r.erase(r.find(a[i].second));
            if (*l.rbegin() <= i && i <= *r.begin()) {
                res.push_back(i);
            }
            l.insert(a[i].first);
            r.insert(a[i].second);
        }
    }
    cout << (int)res.size() << '\n';
    for (auto &e : res) {
        cout << e + 1 << '\n';
    }
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