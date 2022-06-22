/* Author: OnMyZenith - https://github.com/OnMyZenith */
#include "bits/stdc++.h"
using namespace std;
using ll = long long;

#ifdef asr_debug
#include "dbg.hpp"
#else
#define dbg(...) 007
#endif


int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << setprecision(15) << fixed;

    int n; cin >> n;
    string s; cin >> s;
    ll ans = (ll) n * (n - 1) / 2;
    dbg(ans);
    vector<int> bad;
    for (int i = 0; i < n;) {
        int cnt = 0;
        for (int j = i; j < n; j++) {
            if (s[i] == s[j]) cnt++;
            else break;
        }
        i += cnt;
        bad.push_back(cnt);
    }
    dbg(bad);
    for (int i = 0; i < (int)bad.size() - 1; i++) {
        ans -= bad[i] + bad[i + 1] - 1;
    }
    cout << ans << '\n';

    return 0;
}