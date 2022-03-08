/* Author: OnMyZenith - https://github.com/OnMyZenith */
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
using ll = long long;

#define vamos ios_base::sync_with_stdio(false), cin.tie(nullptr), cout << setprecision(15) << fixed;
#ifdef asr_debug
#include "dbg.hpp"
#else
#define dbg(...) 007
#endif




void solve() {
    int n, m; cin >> n >> m;
    vector<pair<int, int>> a(m);
    vector<int> b;
    vector<int> idx(m); iota(idx.begin(), idx.end(), 0);
    for (int i = 0; i < m; i++) {
        cin >> a[i].first >> a[i].second;
    }
    sort(idx.begin(), idx.end(), [&](int i, int j){return a[i].second < a[j].second;});
    ll w = 0;
    for (int i = 0; i < 2 * n; i++) {
        b.push_back(idx[i]);
    }
    for (int i = 0; i < 2 * n; i++) {
        w += a[b[i]].second;
    }
    sort(b.begin(), b.end(), [&](int i, int j){return a[i].first < a[j].first;});
    cout << w << '\n';
    for (int i = 0; i < n; i++) {
        cout << b[i] + 1 << " " << b[2 * n - 1 - i] + 1 << '\n';
    }
    // cout << '\n';
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