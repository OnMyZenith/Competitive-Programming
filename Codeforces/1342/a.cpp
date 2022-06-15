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
    ll x, y, a, b; cin >> x >> y >> a >> b;
    if(x == 0 && y == 0) {
        cout << "0\n";
        return;
    }
    if(2 * a <= b) {
        cout << (x + y) * a << '\n';
        return;
    }
    cout << min(x, y) * b + abs(x - y) * a << '\n';



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