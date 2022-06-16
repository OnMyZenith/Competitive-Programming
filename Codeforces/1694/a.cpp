/* Author: OnMyZenith - https://github.com/OnMyZenith */
#include "bits/stdc++.h"
using namespace std;
using ll = long long;

#ifdef asr_debug
#include "dbg.hpp"
#else
#define dbg(...) 007
#endif


void solve() {
    int a, b; cin >> a >> b;
    if(a > b) {
        for (int i = 0; i < min(a, b); i++) {
            cout << "01";
        }
        for (int i = 0; i < a - b; i++) {
            cout << "0";
        }
        cout << '\n';
    }else  {
        for (int i = 0; i < min(a, b); i++) {
            cout << "10";
        }
        for (int i = 0; i < b - a; i++) {
            cout << "1";
        }
        cout << '\n';
    }

}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << setprecision(15) << fixed;

    int TT = 1;
    cin >> TT;
    while(TT--) {
        solve();
    }

    return 0;
}