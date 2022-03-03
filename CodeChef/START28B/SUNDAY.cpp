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
    vector<int> a(n);
    for (auto &u : a) {
        cin >> u;
    }
    sort(a.begin(), a.end());
    set<int> s(a.begin(), a.end());
    int ans = 0;
    for (int i = 1; i <= 30; i++) {
        if(i % 7 == 6 || i % 7 == 0 || s.count(i)) ans++;
    }
    cout << ans << '\n';
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