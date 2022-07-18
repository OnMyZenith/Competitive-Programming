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
    int n, m; cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    string s(m, 'B');
    for (int i = 0; i < n; i++) {
        int idx = min(a[i] - 1, m - a[i]);
        if (s[idx] == 'B') s[idx] = 'A';
        else s[max(a[i] - 1, m - a[i])] = 'A';
    }
    cout << s << '\n';
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
