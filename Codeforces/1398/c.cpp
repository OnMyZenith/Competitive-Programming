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
    int n; string s; cin >> n >> s;
    vector<int> a(n);
    for (int i = 0; i < n; i++) a[i] = s[i] - '1';

    vector<int> pre(n + 1);
    for (int i = 0; i < n; i++) pre[i + 1] = pre[i] + a[i];

    map<int, int> mp;
    mp[0] = 1;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans += mp[pre[i + 1]];
        mp[pre[i + 1]]++;
    }
    dbg(mp);

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