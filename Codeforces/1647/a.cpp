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
    if(n % 3 == 0) {
        bool f = 0;
        while(n) {
        if(f) {
            n--;
            cout << 1;
        } else {
            n -= 2;
            cout << 2;
        }
            f = !f; 
        }
        cout << '\n';
        return;
    }
    if(n % 3 == 1) {
        bool f = 1;
        while(n) {
        if(f) {
            n--;
            cout << 1;
        } else {
            n -= 2;
            cout << 2;
        }
            f = !f; 
        }
        cout << '\n';
        return;
    }
    bool f = 0;
    while(n) {
        if(f) {
            n--;
            cout << 1;
        } else {
            n -= 2;
            cout << 2;
        }
        f = !f; 
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