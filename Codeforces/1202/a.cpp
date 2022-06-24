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
    string x, y; cin >> x >> y;
    reverse(x.begin(), x.end());
    reverse(y.begin(), y.end());

    int x1 = -1, y1 = -1;
    for (int i = 0; i < (int)y.size(); i++) {
        if (y[i] == '1') {
            y1 = i;
            break;
        }
    }
    for (int i = y1; i < (int)x.size(); i++) {
        if (x[i] == '1') {
            x1 = i;
            break;
        }
    }
    cout << max(x1 - y1, 0) << '\n';
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