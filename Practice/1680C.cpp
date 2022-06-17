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
    string s; cin >> s;
    int n = (int)s.size();
    vector<int> pos, pre(n + 1);
    for (int i = 0; i < n; i++) {
        if(s[i] == '1') pos.push_back(i);
        pre[i + 1] = pre[i]+ (s[i] == '0');
    }
    int m = (int)pos.size();
    int lo = 0, hi = m;
    while (lo < hi) {
        int removed_1s = (lo + hi) / 2;
        bool pass = 0;
        for (int i = 0; i < removed_1s + 1; i++) {
            int r = i + (m - removed_1s) - 1;
            pass |= pre[pos[r] + 1] - pre[pos[i]] <= removed_1s;
        }
        if(pass) {
            hi = removed_1s;
        } else {
            lo = removed_1s + 1;
        }
    }
    cout << lo << '\n';
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