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
    vector<int> a(n), pre_max(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    set<int> s(a.begin(), a.end());
    bool fail = 0;
    for (int i = 0; i < n;) {
        dbg(s, *s.rbegin());
        if (a[i] == (*s.rbegin())) {
            fail = 1;
            break;
        } else {
            for (int j = i + 1; j < n; j++) {
                if ((int)s.size() == 1) break;
                if (a[j] == (*s.rbegin())) {
                    s.erase(a[j]);
                    a[j] = a[i];
                    i = j;
                    break;
                } else s.erase(a[j]);
            }
            if ((int)s.size() == 1) break;
        }
    }
    cout << (fail ? "NO\n" : "YES\n");
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