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
    string s; cin >> s;
    int n = (int)s.size();
    bool p = (s[n - 1] - '0') & 1;
    for (int i = 0; i < n - 1; i++) {
        if(((s[i] - '0') & 1) == p) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO" << '\n';
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