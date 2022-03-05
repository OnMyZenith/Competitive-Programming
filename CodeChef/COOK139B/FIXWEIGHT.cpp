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
    ll n, x; cin >> n >> x;
    for (int len = 1; len <= n; len++) {
        if(x % len == 0 && 1 <= (x / len) && (x / len) <= (n + 1 - len)) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
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