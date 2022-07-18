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
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<vector<pair<int, int>>> res(n);
    for (int i = 0; i < n;) {
        int cnt = 0;
        for (int j = i; j < n && a[i] == a[j]; j++, cnt++);
        res[a[i] - 1].push_back({i, i + cnt - 1});
        i += cnt;
    }
    for (auto &v : res) {
        if (v.empty()) {
            cout << "0 ";
            continue;
        }
        
        int cnt = v[0].second - v[0].first + 1;
        for (int i = 0; i < (int)v.size() - 1; i++) {
            cnt += v[i + 1].second - v[i + 1].first + 1;
            cnt -= (v[i + 1].first - v[i].second - 1) & 1;
        }
        cout << cnt << ' ';
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
