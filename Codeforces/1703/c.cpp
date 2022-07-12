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
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) {
        int moves; cin >> moves;
        string s; cin >> s;
        int cnt = 0;
        for (auto &c : s) {
            cnt += (c == 'U' ? 1 : -1);
        }
        cnt = 10 - cnt;
        cnt %= 10;
        if (cnt < 0) cnt += 10;
        a[i] += cnt;
        a[i] %= 10;
        cout << a[i] << " \n"[i == n - 1];
    }
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
