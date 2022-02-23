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
    int n; cin >> n;
    vector<int> a(n - 2);
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if(!i || i == n - 1) continue;
        a[i - 1] = x;
    }
    int odd = 0, even = 0, prob = 0;
    for (auto &u : a) {
        if(u & 1) {
            odd++;
            if(u == 1) prob++;
        }
        else even++;
    }
    ll ans = (accumulate(a.begin(), a.end(), 0LL) + odd) / 2;
    if((odd == 1 && !even )|| (odd == prob && !even)) {
        cout << "-1\n"; return;
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