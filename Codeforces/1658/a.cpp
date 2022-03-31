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
    vector<int> pos0;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if(s[i] == '0') pos0.push_back(i);
    }
    for (int i = 0; i < (int)pos0.size() - 1; i++) {
        if(pos0[i + 1] - pos0[i] == 1) ans += 2;
        if(pos0[i + 1] - pos0[i] == 2) ans++;
    }
    dbg(pos0);
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