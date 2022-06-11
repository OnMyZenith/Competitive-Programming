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
    int n = (int)s.size();
    int ans = 0, p = 0, b = 0;
    for (int i = 0; i < n; i++) {
        if(s[i] == '[' || s[i] == ']') {
            if (s[i] == '[') {
                b++; 
            } else if (b > 0) {
                b--;
                ans++;
            }
        }
        if(s[i] == '(' || s[i] == ')') {
            if (s[i] == '(') {
                p++; 
            } else if (p > 0) {
                p--;
                ans++;
            }
        }
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