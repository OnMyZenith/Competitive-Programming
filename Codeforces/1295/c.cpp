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
    string s, t; cin >> s >> t;
    int n = (int)t.size();
    set<char> allt(t.begin(), t.end());

    vector<vector<int>> pos(26);
    vector<int> curr(26, -1);
    for (int i = 0; i < (int)s.size(); i++) {
        if (allt.count(s[i])) {
            pos[s[i] - 'a'].push_back(i);
        }
    }
    dbg(pos);
    int ans = 1, last = -1;
    for (int i = 0; i < n; i++) {
        if (pos[t[i] - 'a'].empty()) {
            cout << "-1\n";
            return;
        }
        // int l = (++curr[t[i] - 'a']) % (int)pos[t[i] - 'a'].size();
        // curr[t[i] - 'a'] = l;

        int l = upper_bound(pos[t[i] - 'a'].begin(), pos[t[i] - 'a'].end(), last) - pos[t[i] - 'a'].begin();
        if (l == (int)pos[t[i] - 'a'].size()) l = 0, ans++;
        // ans += pos[t[i] - 'a'][l] <= last;
        last = pos[t[i] - 'a'][l];
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