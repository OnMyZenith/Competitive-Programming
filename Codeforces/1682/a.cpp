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
    int cnt = 0;
    for (int i = n / 2; i < n; i++) {
        if(s[i] == s[n / 2]) cnt++;
        else break;
    }
    dbg(cnt);
    cout << cnt * 2 - (n & 1) << '\n';


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