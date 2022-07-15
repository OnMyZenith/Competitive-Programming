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
    int n, x; cin >> n >> x;
    vector<int> a(2 * n);
    for (auto &u : a) {
        cin >> u;
    }
    sort(a.begin(), a.end());
    bool poss = 1;
    for (int i = 0; i < n; i++) {
        poss &= a[i] + x <= a[i + n];
    }
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
