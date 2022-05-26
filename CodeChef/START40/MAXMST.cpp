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
    ll n, m;
    cin >> n >> m;
    vector<ll> a(m);
    for (ll i = 0; i < m; i++) cin >> a[i];

    sort(a.begin(), a.end());

    ll j = m - 1;
    ll ans = 0;
    for (ll i = n - 1; i >= 1; i--) {
        ll max = i * (i - 1) / 2;
        ll rem = j - max;

        if (rem <= 0) ans += a[j--];
        else {
            j -= rem;
            ans += a[j--];
        }
    }
    cout << ans << '\n';
}

int main() {
    vamos;

    int TT = 1;
    cin >> TT;
    while (TT--) {
        solve();
    }

    return 0;
}