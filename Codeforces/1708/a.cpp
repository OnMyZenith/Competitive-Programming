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
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    bool poss = 1;
    for (int i = 1; i < n && poss; i++) {
        poss &= a[i] % a[i - 1] == 0;
        a[i] = a[i - 1];
    }


    // int need = a[n - 1] % a[n - 2];
    // bool poss = 1;
    // for (int i = n - 3; i >= 0 && poss; i--) {
    //     poss &= (a[i + 1] - need) >= 0 && (a[i + 1] - need) % a[i] == 0;
    // }
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
