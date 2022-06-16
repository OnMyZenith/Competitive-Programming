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
    string s; cin >> s;
    int l = -1, r = -1;
    int n = (int)s.size();
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            l = i;
            break;
        }
    }
    for (int i = n; i >= 0; i--) {
        if (s[i] == '1') {
            r = i;
            break;
        }
    }
    if(l == -1) {
        cout << "0\n";
        return;
    }

    cout << count(s.begin() + l, s.begin() + r + 1, '0') << '\n';
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