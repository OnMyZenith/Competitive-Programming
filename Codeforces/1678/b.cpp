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
    int n; cin >> n;
    string s; cin >> s;
    int fix = 0, cnt = 1;
    int good_prev = -1;
    for (int i = 0; i < n; i += 2) {
        if(s[i] != s[i + 1]) fix++;
        else {
            if (good_prev != -1 && good_prev != s[i]) cnt++;
            good_prev = s[i];
        }
    }
    cout << fix << " " << cnt << '\n';
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