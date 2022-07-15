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
    int n;
    cin >> n;
    string s, t; cin >> s >> t;
    if (s.front() != t.front() || s.back() != t.back()) {
        cout << "-1\n";
        return;
    }

    auto cal = [&](const string &str) -> vector<pair<int, int>> {
        vector<pair<int, int>> ret;
        for (int i = 0; i < n;) {
            while (i < n && str[i] == '0') {
                i++;
                continue;
            }
            if (i == n) break;
            int cnt = 0;
            for (int j = i; j < n; j++, cnt++) {
                if (str[j] == '0') break;
            }
            ret.push_back({i, cnt + i - 1});
            i += cnt;
        }
        return ret;
    };

    auto v1 = cal(s);
    auto v2 = cal(t);
    if ((int)v1.size() != (int)v2.size()) {
        cout << "-1\n";
        return;
    }
    dbg(v1, v2);
    int m = (int)v1.size();
    ll ans = 0;
    for (int i = 0; i < m; i++) {
        ans += abs(v1[i].first - v2[i].first);
        ans += abs(v1[i].second - v2[i].second);
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
