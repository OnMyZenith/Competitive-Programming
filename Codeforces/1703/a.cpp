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
    string yes;
    cin >> yes;
    bool poss = (yes[0] == 'Y') || (yes[0] == 'y');
    poss &= (yes[1] == 'E') || (yes[1] == 'e');
    poss &= (yes[2] == 'S') || (yes[2] == 's');
    cout << (poss ? "YES" : "NO") << '\n';


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
