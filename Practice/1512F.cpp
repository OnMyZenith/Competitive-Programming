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
    int n; ll c; cin >> n >> c;
    vector<ll> a(n), b(n - 1);
    for (auto &u : a) {
        cin >> u;
    }
    for (auto &u : b) {
        cin >> u;
    }
    vector<ll> days(n), started_at(n);
    for (int i = 0; i < n - 1; i++) {
        ll req_days = (b[i] - started_at[i] + a[i] - 1) / a[i] + 1;
        req_days = max(req_days, 1LL);
        days[i + 1] = days[i] + req_days;
        started_at[i + 1] = started_at[i] + ((req_days - 1) * a[i]) - b[i];
    }
    ll ans = 1e10;
    for (int i = 0; i < n; i++) {
        ans = min(ans, (c - started_at[i] + a[i] - 1) / a[i] + days[i]);
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