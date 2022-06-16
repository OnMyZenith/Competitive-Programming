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
    ll n; string s; cin >> n >> s;
    ll res = n;
    for (int i = 0; i < n; i++) {
        if (i && s[i] == '1' && s[i - 1] == '0') res += i;
        if (i && s[i] == '0' && s[i - 1] == '1') res += i;
    }
    cout << res << '\n';
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