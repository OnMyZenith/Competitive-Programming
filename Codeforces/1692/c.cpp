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
    vector<string> a(8);
    for (int i = 0; i < 8; i++) {
        cin >> a[i];
    }
    for (int i = 1; i < 7; i++) {
        for (int j = 1; j < 7; j++) {
            if(a[i][j] == '#' && a[i - 1][j - 1] == '#' && a[i - 1][j + 1] == '#' && a[i + 1][j - 1] == '#' && a[i + 1][j + 1] == '#') {
                cout << i + 1 << " " << j + 1 << '\n';
                return;
            }
        }
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