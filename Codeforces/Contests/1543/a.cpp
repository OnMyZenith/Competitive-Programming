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
    ll a, b; cin >> a >> b;
    if(a == b) {cout << "0 0\n"; return;}
    if(a < b) swap(a, b);
    ll d = a - b;
    if(b % d == 0) {cout << gcd(a, b) << " 0\n"; return;}
    ll ans = (b / d + 1) * d - b;
    ll a2 = (b / d) * d - b;
    if(ans < abs(a2)) {
        cout << gcd(a + ans, b + ans) << " " << ans << '\n';
    } else {
        cout << gcd(a + a2, b + a2) << " " << abs(a2) << '\n';
    }
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