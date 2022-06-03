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
    vector<int> cnt(26);
    for (int i = 0; i <= 2 * n; i++) {
        string a;
        cin >> a;
        for (auto &c : a) {
            cnt[c - 'a']++;
        }
    }
    for (int i = 0; i < 26; i++)  {
        if(cnt[i] & 1) {
            cout << char(i + 'a') << '\n';
            return;
        }
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