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
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int idx = -1;
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        if(b[i]) idx = i;
    }
    if(idx == -1) {
        cout << "YES\n";
        return;
    }
    int diff = a[idx] - b[idx];
    bool pass = diff >= 0;

    for (int i = 0; i < n; i++) {
        pass &= (((a[i] - b[i]) == diff) || (((a[i] - b[i]) <= diff) && (b[i] == 0)));
    }
    cout << (pass ? "YES" : "NO") << '\n';
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