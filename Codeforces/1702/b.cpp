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
    set<char> all;
    int days = 0, cnt = 0;
    for (auto &c : s) {
        if (all.count(c)) continue;
        if (cnt == 0) all.clear();
        all.insert(c);
        cnt++;
        if (cnt == 3) cnt = 0, days++;
    }
    // dbg(days, cnt);
    cout << days + !!(cnt) << '\n';
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