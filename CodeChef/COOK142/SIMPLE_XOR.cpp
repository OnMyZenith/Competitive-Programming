/* Author: OnMyZenith - https://github.com/OnMyZenith */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef asr_debug
#include "dbg.hpp"
#else
#define dbg(...) 007
#endif


void solve() {
    int l, r; cin >> l >> r;

    for (int i = 0; i < 10 && l + 3 <= r; i++) {
        if(l & 1) l++;
        else {
            cout << l << " " << l + 1 << " " << l + 2 << " " << l + 3 << '\n';
            return;
        }
    }
    cout << -1 << '\n';

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