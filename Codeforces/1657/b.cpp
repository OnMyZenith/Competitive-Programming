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
    ll n, b, x, y; cin >> n >> b >> x >> y;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++) {
        a[i] = a[i - 1] + (a[i - 1] + x <= b ? x : -y);
    }
    dbg(a);
    cout << accumulate(a.begin(), a.end(), 0LL) << '\n';
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