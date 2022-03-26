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
    vector<vector<ll>> elements_of_freq(n + 1); // Key observation -> there can only be sqrt(n) unique frequencies
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
        elements_of_freq[freq].push_back(ele);
    }
    vector<ll> f;
    for (int i = 0; i < n; i++) {
        if(elements_of_freq[i].empty()) continue;
        f.push_back(i);
        sort(elements_of_freq[i].rbegin(), elements_of_freq[i].rend());
    }

    for (int i = 0; i < (int)f.size(); i++) {
        for (int j = 0; j < (int)f.size(); j++) {
            if(f[i] < f[j]) continue;
            for (auto &x : elements_of_freq[f[i]]) {
                for (auto &y : elements_of_freq[f[j]]) {
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