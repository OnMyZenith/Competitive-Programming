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
    int s, i, ex; cin >> s >> i >> ex;
    if (i + 1 <= s) {
        int EX = ex;
        ex += s - (i + 1);
        cout << min(ex / 2, EX) + 1 << '\n';
        return;
    }
    ex -= i + 1 - s;
    if (ex < 0) {
        cout << "0\n";
        return;
    }
    cout << ex / 2 + 1 << '\n';
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