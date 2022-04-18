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
    int n; string s; cin >> n >> s;
    vector<ll> sum(n + 1), dn(n + 1);
    for (int i = 0; i < n - 1; i++) {
        if(s[i] == '-' && s[i] == s[i + 1]) {
            dn[i + 2] = 1;
            // dn[i + 1] = max(dn[i], dn[i + 1]);
            i++;
        } 
        // else dn[i + 1] = max(dn[i], dn[i + 1]), dn[i + 2] = max(dn[i], dn[i + 2]);
    }
    for (int i = 0; i < n; i++) dn[i + 1] += dn[i];
    for (int i = 0; i < n; i++) {
        sum[i + 1] = sum[i] + (s[i] == '+' ? 1 : -1);
    }
    dbg(dn);
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            ll neg = dn[j + 1] - dn[i];
            ll sm = sum[j + 1] - sum[i];
            ans += (sm <= 0 && sm % 3 == 0 && neg * 3 >= sm);
            if((sm <= 0 && sm % 3 == 0 && neg * 3 >= sm)){
                dbg(i, j);
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