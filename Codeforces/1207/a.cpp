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
    int b, p, c; cin >> b >> p >> c;
    int H, C; cin >> H >> C;
    if (H > C) {
        if (b - 2 * p <= 1) {
            cout << (b / 2) * H << '\n';
            return;
        }
        b -= 2 * p;
        cout << p * H + min(b / 2, c) * C << '\n';
    } else {
        if (b - 2 * c <= 1) {
            cout << (b / 2) * C << '\n';
            return;
        }
        b -= 2 * c;
        cout << c * C + min(b / 2, p) * H << '\n';
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