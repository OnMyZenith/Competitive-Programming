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
    if(n < 2) {
        cout << "NO\n";
        return;
    }
    for (int i = 0, a = 0, b = 0; i < n; i++) {
        a += s[i] == 'A';
        b += s[i] == 'B';
        if(b > a) {
            cout << "NO\n";
            return;
        }
        if((i == n - 1) && s[i] == 'A') {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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