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
    string s; cin >> s;
    int n = (int)s.size();
    
    vector<ll> suff1(n + 1);
    vector<ll> pre0(n + 1);
    for (int i = 0; i < n; i++) {
        pre0[i + 1] = pre0[i] + (s[i] == '0');
    }
    for (int i = n - 1; i >= 0; i--) {
        suff1[i] = suff1[i + 1] + (s[i] == '1');
    }

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        cnt += pre0[i] == 0 && suff1[i + 1] == 0;
    }
    cout << max(cnt, 1) << '\n';
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