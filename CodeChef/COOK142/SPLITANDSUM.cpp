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
    vector<ll> a(n);
    vector<ll> pre(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        pre[i + 1] = pre[i] + a[i];
    }
    ll sum = 0;
    for (int bit = 0; bit < 60; bit++) {
        sum = 0;
        vector<pair<int, int>> ans = {{0, -1}};
        bool fail = 0;
        for (int i = 0; i < n; i++) {
            sum += a[i];
            if((sum >> bit) & 1LL) sum = 0, ans.back().second = i, ans.push_back({i + 1, -1});
            else if(i == n - 1) {
                ans.pop_back(); fail = 1;
                while(!ans.empty() && !(((pre[n] - pre[ans.back().first]) >> bit) & 1LL)) {
                    ans.pop_back();
                }
                if(!ans.empty() && (((pre[n] - pre[ans.back().first]) >> bit) & 1LL)) {
                    ans.back().second = n - 1;
                    ans.push_back({-1, -1}); sum = 0; fail = 0;
                }
            }
        }
        // dbg(ans);
        if(!sum && !fail && (int)ans.size() >= 3) {
            ans.pop_back();
            cout << "YES\n";
            cout << (int)ans.size() << '\n';
            for (auto &[x, y] : ans) {
                cout << x + 1 << " " << y + 1 << '\n';
            }
            return;
        }
    }
    cout << "NO\n";
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