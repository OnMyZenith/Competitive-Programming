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
    int n, m, x, y; cin >> n >> m >> x >> y;
    ll ans = 0;
    auto res = [&](ll len) -> ll {
        return (2 * x > y ? (len / 2) * y + x * (len & 1) : x * len);
    };
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (int j = 0, cnt = 0; j < m; j++) {
            if (s[j] == '*') {
                if (cnt) {
                    ans += res(cnt);
                    cnt = 0;
                }
            } else {
                cnt++;
            }
            if (j == m - 1) {
                ans += res(cnt);
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