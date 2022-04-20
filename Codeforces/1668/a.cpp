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
    int n, m; cin >> n >> m;
    if(n == 1 && m == 1) {
        cout << "0\n";
        return;
    }
    if((n == 1 && m == 2) || (m == 1 && n == 2)) {
        cout << "1\n";
        return;
    }
    if(n == 1 || m == 1) {
        cout << "-1\n";
        return;
    }
    if (n < m) swap(n, m);
    int x = n - m;

    cout << (m - 1) * 2 + (x / 2) * 4 + int(x & 1) << '\n';
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