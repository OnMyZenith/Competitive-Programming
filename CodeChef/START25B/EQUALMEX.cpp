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
    int n ; cin >> n;
    vector<int> v(2*n);
    vector<int> f(n+2);
    for (auto &u : v) {
        cin >> u;
        f[u]++;
    }
    dbg(f);
    for (int i = 0; i <= n+1; i++) {
        if(f[i]>=2) continue;
        if(!f[i]) {
            cout << "YES\n";
            return;
        }
        if(f[i]==1) {
            cout << "NO\n";
            return;
        }
    }
    cout << "NO\n";




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