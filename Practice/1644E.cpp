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
    ll n; string s; cin >> n >> s;
    ll cantVis = 0;
    for (int i = 0; i < (int)s.size(); i++) {
        if(s[i] != s[0]) {
            int cntd = 0, cntr = 0;
            for (int j = i; j < (int)s.size(); j++) {
                cntd += s[j] == 'D';
                cntr += s[j] == 'R';
            }
            cantVis = (ll)(n - 1) * i;
            cantVis += (ll)(cntd + 1) * (cntr + 1) - cntd - cntr - 1;
            break;
        }
    }
    if(!count(s.begin(), s.end(), 'R') || !count(s.begin(), s.end(), 'D')) cantVis = (ll)(n - 1) * n;
    cout << n * n - cantVis << '\n';
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