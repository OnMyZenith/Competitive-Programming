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
    int n, k; cin >> n >> k;
    string s; cin >> s;
    int one = count(s.begin(), s.end(), '1');
    ll res = (ll) 11 * one;
    int l = -1, r = -1;
    for (int i = 0; i < n; i++) {
        if(s[i] == '1') {
            l = i;
            break;
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        if(s[i] == '1') {
            r = i;
            break;
        }
    }
    int rcost = n - r - 1;
    if(one)
        if(r == l) {
            if(rcost <= k) res -= 10;
            else if(l <= k) res -= 1;
        } else {
            if(rcost <= k) res -= 10, k -= rcost;
            
            if(l <= k) res -= 1, k -= l;
        }
    cout << res << '\n';
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