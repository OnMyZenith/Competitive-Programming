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
    int a, b; cin >> a >> b;
    if((a%3 == 0) || (b%3 == 0)) {
        cout << "0\n";
        return;
    }
    // a %=3;
    // b %=3;

    cout << 1 + !!(abs(a - b) % 3) << '\n';



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