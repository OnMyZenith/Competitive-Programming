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
    vector<vector<int>> g(n);
    set<int> rem;
    for (int i = 0; i < n; i++) rem.insert(i + 1);
    vector<bool> done(n);
    for (int i = 0; i < n; i++) {
        int d; cin >> d;
        g[i].resize(d);
        for (auto &u : g[i]) {
            cin >> u;
            if(!done[i] && rem.count(u)) {
                rem.erase(u);
                done[i] = 1;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if(!done[i]) {
            cout << "IMPROVE\n";
            cout << i + 1 << " " << *rem.begin() << '\n';
            return;
        }
    }
    cout << "OPTIMAL\n";
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