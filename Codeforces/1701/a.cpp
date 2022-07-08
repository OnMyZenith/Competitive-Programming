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
    vector<int> a(4);
    bool a0 = 1, a1 = 1;
    for (auto &e : a) {
        cin >> e;
        a0 &= !e;
        a1 &= e;
    }
    if (!(a0 || a1)) {
        cout << 1 << '\n';
    } else {
        cout << (a0 ? 0 : 2) << '\n';
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