/* Author: OnMyZenith - https://github.com/OnMyZenith */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define vamos ios_base::sync_with_stdio(false), cin.tie(nullptr), cout << setprecision(15) << fixed;
#ifdef asr_debug
#include "dbg.hpp"
#else
#define dbg(...) 007
#endif

template <class T> bool ckmin(T &x, const T &y) { return (y < x) ? (x = y, 1) : 0; }
template <class T> bool ckmax(T &x, const T &y) { return (y > x) ? (x = y, 1) : 0; }

void solve() {
    ll n, m; ll ans = 0; cin >> n >> m;
    vector<ll> a(n);
    vector<pair<ll, ll>> bad;
    map<ll, ll> cnt;
    vector<vector<ll>> ele_of_freq(n + 1); // Key observation -> there can only be sqrt(n) unique frequencies
    for (auto &u : a) {
        cin >> u;
        cnt[u]++;
    }
    for (int i = 0; i < m; i++)  {
        ll x, y; cin >> x >> y;
        bad.push_back({x, y});
    }
    sort(bad.begin(), bad.end());
    for (auto &[ele, freq] : cnt) {
        ele_of_freq[freq].push_back(ele);
    }
    vector<ll> f;
    for (int i = 0; i < n; i++) {
        if(ele_of_freq[i].empty()) continue;
        f.push_back(i);
        sort(ele_of_freq[i].rbegin(), ele_of_freq[i].rend());
    }

    for (int i = 0; i < (int)f.size(); i++) {
        for (int j = i; j < (int)f.size(); j++) {
            for (auto &x : ele_of_freq[f[i]]) {
                for (auto &y : ele_of_freq[f[j]]) {
                    pair fin{min(x, y), max(x, y)};
                    if(x != y && !binary_search(bad.begin(), bad.end(), fin)) {
                        ckmax(ans, (x + y) * (f[i] + f[j]));
                        break;
                    }
                }
            }
        }
    }
    cout << ans << '\n';
}

int main() {
    vamos;

    int TT = 1;
    cin >> TT;
    while(TT--) {
        solve();
    }

    return 0;
}