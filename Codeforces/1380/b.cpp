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
    string s;
    cin >> s;
    int r = 0, p = 0, sc = 0;
    for (auto &c : s) {
        if (c == 'R') r++;
        else if (c == 'P')
            p++;
        else
            c = sc++;
    }
    if (r == max({r, p, sc})) {
        cout << string((int)s.size(), 'P') << '\n';
    } else if (p == max({r, p, sc}))
        cout << string((int)s.size(), 'S') << '\n';
    else
        cout << string((int)s.size(), 'R') << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << setprecision(15) << fixed;

    int TT = 1;
    cin >> TT;
    while (TT--) {
        solve();
    }

    return 0;
}