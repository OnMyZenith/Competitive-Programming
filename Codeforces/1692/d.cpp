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
    string curr; int x; cin >> curr >> x;
    int h, m;
    m = (curr[3] - '0') * 10 + (curr[4] - '0');
    h = (curr[0] - '0') * 10 + (curr[1] - '0');
    int ans = 0;
    for (int i = 0; i < 24; i++) {
        int h1 = i;
        int m1 = i / 10 + (i % 10) * 10;
        if(m1 >= 60) continue;
        int req = (h1 * 60 + m1 - (h * 60  + m));
        if (req < 0) req += 24 * 60;

        bool pass = 0;
        for (int j = 0; j <= 24 * 60; j++) {
            pass |= ((x * j) % (24 * 60)) == req;
        }

        // dbg(x, req);
        // ans += x == gcd(x, req);
        ans += pass;
    }
    cout << ans << '\n';
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