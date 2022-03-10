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
    int n, q; string a, b; cin >> n >> q >> a >> b;
    vector<ll> rot(n + 1);
    for (int i = n - 1; i >= 0; i--) {
        rot[i] = b[i] - a[i] - rot[i + 1];
    }
    for (int i = 0; i < q; i++) {
        ll l, r; cin >> l >> r; l--, r--;
        if(l == r) cout << (a[l] == b[l] ? "Yes" : "No") << '\n';
        else cout << ((rot[r + 1] * ((r - l + 1) & 1 ? 1 : -1) + rot[l]) % 26 == 0 ? "Yes" : "No") << '\n';
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