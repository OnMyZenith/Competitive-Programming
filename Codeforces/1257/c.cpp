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
    int n; cin >> n;
    vector<int> a(n), last_seen(n, -1);
    int ans = 1e9;
    for (int i = 0; i < n; i++) {
        cin >> a[i], --a[i];
        if (last_seen[a[i]] == -1) {
            last_seen[a[i]] = i;
        } else {
            ans = min(ans, i - last_seen[a[i]] + 1);
            last_seen[a[i]] = i;
        }
    }
    cout << (ans != int(1e9) ? ans : -1) << '\n';
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