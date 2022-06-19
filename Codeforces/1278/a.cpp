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
    string p, s; cin >> p >> s;
    int n = (int)p.size();
    multiset<int> tt(p.begin(), p.end());
    for (int i = 0; i < (int)s.size() - n + 1; i++) {
        if (multiset<int>(s.begin() + i, s.begin() + i + n) == tt) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
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