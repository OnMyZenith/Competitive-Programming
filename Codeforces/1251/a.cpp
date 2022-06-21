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
    vector<int> odd(26);
    int n = (int)s.size();
    for (int i = 0; i < n;) {
        int cnt = 0;
        for (int j = i; j < n; j++) {
            if (s[j] == s[i]) cnt++;
            else break;
        }
        odd[s[i] - 'a'] |= cnt & 1;
        i += cnt;
    }
    for (int i = 0; i < 26; i++) {
        if (odd[i]) cout << char(i + 'a');
    }
    cout << '\n';
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