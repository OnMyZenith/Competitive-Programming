/* Author: OnMyZenith - https://github.com/OnMyZenith */
#include "bits/stdc++.h"
using namespace std;
using ll = long long;

#ifdef asr_debug
#include "dbg.hpp"
#else
#define dbg(...) 007
#endif

bool f(string &s) {
    int cnt = 0, n = (int)s.size();
    for (int i = 0; i < n; i++) {
        cnt += '(' == s[i];
        cnt -= ')' == s[i];
        if (cnt < 0) {
            return 0;
        }
    }
    return cnt == 0;
}

void solve() {
    string s; cin >> s;
    int n = (int)s.size();

    int open = n / 2;
    for (int i = 0; i < n; i++) {
        open -= s[i] == '(';
    }

    int l = -1, r = -1;
    for (int i = 0, co = 0; i < n; i++) {
        if (s[i] == '?') {
            if (co++ < open) s[i] = '(';
            else s[i] = ')';

            if (co == open) l = i;
            if (co == open + 1) r = i;
        }
    }
    dbg(s);
    if (l != -1 && r != -1) swap(s[l], s[r]), dbg(s);

    cout << (l == -1 || r == -1 || !f(s) ? "YES" : "NO") << '\n';
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
