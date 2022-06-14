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
    ll a, b, c, d; cin >> a >> b >> c >> d;
    if (a <= b) {
        cout << b << '\n';
        return;
    }
    if(d >= c) {
        cout << "-1\n";
        return;
    }
    ll need = a - b + d;
    dbg(need);
    ll t = b + c +  c * ((need - c + c - d - 1) / (c - d));
    // ll t = b + c;
    // while (need > c) {
    //     t += c;
    //     need -= c;
    //     need += d;
    //     // dbg(need);
    // }
    cout << t << '\n';
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