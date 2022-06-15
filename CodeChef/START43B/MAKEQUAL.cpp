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
    ll a[3]; cin >> a[0] >> a[1] >> a[2];

    for (int j = 0; j < 60; j++) {
        if(a[0] == a[1] && a[1] == a[2]) {
            cout << "YES\n";
            return;
        }

        int isset = 0;
        for (int i = 0; i < 3; i++) {
            if(1 & (a[i] >> j)) isset++;
        }
        if(isset == 2) {
            for (int i = 0; i < 3; i++) {
                if(!(1 & (a[i] >> j))) a[i] |= 1ll << j;
            }
        } else if (isset == 1) {
            for (int i = 0; i < 3; i++) {
                if(1 & (a[i] >> j)) a[i] += 1ll << j;
            }
        } else {
            break;
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