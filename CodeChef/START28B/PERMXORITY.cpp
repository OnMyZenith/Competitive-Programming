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
    if(n == 2) {
        cout << "-1\n";
        return;
    }
    if(n & 1) {
        for (int i = 0; i < n; i++) cout << i + 1 << " \n"[i == n - 1];
        return;
    }
    n /= 2;
    if(n & 1) {
        cout << "1 4 6 3 2 5";
        n -= 3;
        int cnt = 7;
        bool f = 1;
        for (; n; n--, cnt += 2, f = !f) {
            if(f) cout << " " << cnt << " " << cnt + 1;
            else cout << " " << cnt + 1 << " " << cnt;
        }
        cout << '\n';
        return;
    }
    cout << "1 4 2 3";
    n -= 2;
    int cnt = 5;
    bool f = 1;
    for (; n; n--, cnt += 2, f = !f) {
        if(f) cout << " " << cnt << " " << cnt + 1;
        else cout << " " << cnt + 1 << " " << cnt;
    }
    cout << '\n';
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