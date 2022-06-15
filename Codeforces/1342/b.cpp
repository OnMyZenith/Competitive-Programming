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
    string t; cin >> t;
    int zeros = count(t.begin(), t.end(), '0'), n = (int)t.size();
    if(!zeros || zeros == n) {
        cout << t << '\n';
    } else {
        string s;
        for (int i = 0; i < n; i++) {
            s += "01";
        }
        cout << s << '\n';
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