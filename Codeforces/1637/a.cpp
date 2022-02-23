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
    bool f = 1;
    vector<int> a(n);
    for (auto &u : a) {
        cin >> u;
    }
    for (int i = 0; i < n - 1; i++) {
        f &= a[i + 1] >= a[i];
    }

    cout << (f ? "NO" : "YES") << '\n';



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